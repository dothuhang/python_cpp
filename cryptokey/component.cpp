#include <pybind11/pybind11.h>

char version[]="1.0";

char const* getVersion() {
	return version;
}

class Crypto {
  private:
    std::string privateKey;
    std::string publicKey;
  public:
    Crypto() {}
    //Crypto(const std::string &privateKey) : privateKey(privateKey) {}
    const std::string &getPrivateKey() const {
      return privateKey;
    }
    const std::string &getPublicKey() const {
      return publicKey;
    }
    void initialize(const std::string &key) { privateKey = key; }
};

namespace py = pybind11;


PYBIND11_MODULE(crypto_component,greetings)
{
  greetings.doc() = "greeting_object 1.0";

  greetings.def("getVersion", &getVersion, "a function returning the version");

  py::class_<Crypto>(greetings, "Crypto",py::dynamic_attr())
        //.def(py::init<const std::string &, const std::string &>())
        .def(py::init())
        .def("initialize", &Crypto::initialize)
        .def("getPrivateKey", &Crypto::getPrivateKey)
        .def("getPublicKey", &Crypto::getPublicKey);
 
}