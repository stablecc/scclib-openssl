# scclib import for OpenSSL

Requires an installed
[OpenSSL Toolkit](https://www.openssl.org).

## installation

OpenSSL version 1.1.0 or greater must be installed in the system.

### openssl development package

Requires OpenSSL development libraries and headers.

On Debian-like distributions:
```
sudo apt-get update
sudo apt-get install libssl-dev
```

On Fedora/Red Hat-like distributions:
```
sudo yum update
sudo yum install openssl-devel
```

On Gentoo:
```
sudo emerge -a dev-libs/openssl
```

## licensing

Original source:
* [BSD 3-Clause License](lic/bsd_3_clause.txt)

External and redistributable:
* [openssl](lic/openssl.txt)
* [googletest](lic/google.txt)
* [bazel (google)](lic/bazel.txt)
