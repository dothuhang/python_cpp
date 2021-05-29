#include <iostream>
#include <string.h>


class Cle {
	private:
	string privateKey;
	string publicKey;
	
	public:
	Cle() {};
	~Cle() {};
	
	void initialize(string &input);
	string getPrivateKey( return privateKey; );
	string getPublicKey( return publicKey; );

}

namespace py = pybind11;


PYBIND11_MODULE(crypto_cle, greetings)
{
  greetings.doc() = "greeting_object 1.0";

  greetings.def("getVersion", &getVersion, "a function returning the version");

  py::class_<Cle>(greetings, "Cle",py::dynamic_attr())
  
        .def(py::init())
        .def("initialize", &Cle::initialize)
        .def("getPrivateKey", &Cle::getPrivateKey)
        .def("getPublicKey", &Cle::getPublicKey);
 
}

