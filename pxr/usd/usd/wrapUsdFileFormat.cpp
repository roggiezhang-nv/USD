//
// Copyright 2022 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/pxr.h"

#include "pxr/usd/usd/usdFileFormat.h"
#include "pxr/usd/sdf/layer.h"
#include "pxr/base/tf/pyStaticTokens.h"

#include <boost/python/bases.hpp>
#include <boost/python/class.hpp>
#include <boost/python/scope.hpp>

using namespace boost::python;

PXR_NAMESPACE_USING_DIRECTIVE

void
wrapUsdFileFormat()
{
    using This = UsdUsdFileFormat;

    scope s = class_<This, bases<SdfFileFormat>, boost::noncopyable>
        ("UsdFileFormat", no_init)

        .def("GetUnderlyingFormatForLayer", 
            &This::GetUnderlyingFormatForLayer)
        .staticmethod("GetUnderlyingFormatForLayer")
        ;

    TF_PY_WRAP_PUBLIC_TOKENS(
        "Tokens",
        UsdUsdFileFormatTokens,
        USD_USD_FILE_FORMAT_TOKENS);
}
