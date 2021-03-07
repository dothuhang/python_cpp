#include <pybind11/pybind11.h>
using namespace std;

char version[]="1.0";

char const* getVersion() {
	return version;
}

char const* greet() {
  return "hello, world";
}

class Company {
  private:
    float capital;
    string address;
  public:
    Company() {}
    Company(const string &address, const float &capital) : address(address), capital(capital) {}
    const string &getAddress() const {
      return address;
    }
    const float &getCapital() const {
      return capital;
    }
    void setCapital(const string &capital_) { capital = capital_; }
    void setAddress(const string &address_) { address = address_; }
};

namespace py = pybind11;


PYBIND11_MODULE(hello_component,greetings)
{
  greetings.doc() = "greeting_object 1.0";
  
  greetings.def("greet", &greet, "a function saying hello");
  greetings.def("getVersion", &getVersion, "a function returning the version");
  
  py::class_<Company>(greetings, "Company",py::dynamic_attr())
        .def(py::init<const string &, const float &>())
        .def("setCapital", &Company::setCapital)
        .def("getCapital", &Company::getCapital)
        .def("setAddress", &Company::setAddress)
        .def("getAddress", &Company::getAddress);
}
