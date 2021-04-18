# python_cpp
Exemple d'utilisation d'un composant en python
Utilise pybind11
apres git clone, faire:
```
cd python_cpp
git submodule init
git submodule update
```

Pour compiler

```
cd hello
make
```

Pour utiliser
```
python3
>>> import hello_component
>>> hello_component.greet()
'hello, world'
>>> hello_component.getVersion()
'1.0'
>>> 
```

Pour utiliser v2.
```
>>> import hello_component
>>> hello_component.greet()
'hello, world'
>>> c=Company("75000", 100)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'Company' is not defined
>>> c=hello_component.Company("75000", 100)
>>> c.getAddress()
'75000'
>>> c.getCapital()
100.0
>>> c.setAddress("94000")
>>> c.getAddress()
'94000'
```
