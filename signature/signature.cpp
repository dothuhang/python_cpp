#include <pybind11/pybind11.h>
#include "micro-ecc/uECC.h"
#include "./cryptokey/cle.cpp"

char version[]="1.0";

const int publicKeySize = uECC_curve_public_key_size(uECC_secp256k1());

char const *getVersion() 
{
    return version;
}



class Signature
{
	private:
	std:string signed_string;

	public:
	
	Signature() {}
	
	~Signature() {}
	
	Signature *sign(std::string &data, std::string &privateKey) 
	{
		
		
		uint8_t binaryPrivate[32];
		hexStringToBin(binaryPrivate, privateKey.c_str());
		
		uint8_t binaryData[32];
		hexStringToBin(binaryData, data.c_str());
			
		uint8_t signatureBin[64];
		
		uECC_sign(binaryPrivate, binaryData, publicKeySize, signatureBin, uECC_secp256k1());
		
		
		binToHexString(this->signed_string, signatureBin, 64);
		
		
		
		return *this;
		
	}
	
	bool verify(std::string &data, std::string &publicKey, Signature signature)
	{
		
		uint8_t *public_key = new uint8_t[publicKeySize];
		
		hexStringToBin(public_key, publicKey.c_str(), 64);
		
		if (uECC_valid_public_key(public_key, uECC_secp256k1()) = 1)		
		{
			uint8_t *signatureBin = new uint8_t[publicKeySize];
		
			hexStringToBin(signatureBin, signature.getString(), 64);
			
			uint8_t *messageBin = new uint8_t[publicKeySize];
			
			uECC_verify(public_key,
					messageBin,
					64,
					signatureBin,
					uECC_secp256k1());	
		}
		
	
	}
	

}

namespace py = pybind11;

PYBIND11_MODULE(signature,greetings)
{
    greetings.doc() = "greeting_object 1.0";
    greetings.def("getVersion", &getVersion, "a function returning the version");

    py::class_<Signature>(greetings, "Signature", py::dynamic_attr())
	    .def(py::init())
	    .def("sign", &Signature::sign)
	    .def("verify", &Signature::verify);

}




