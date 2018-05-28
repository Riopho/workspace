# ifndef BOOST_PREPROCESSOR_REPETITION_ENUM_SHIFTED_PARAMS_HPP
# define BOOST_PREPROCESSOR_REPETITION_ENUM_SHIFTED_PARAMS_HPP

# include "behaviac/base/meta/boost/dec.hpp"
# include "behaviac/base/meta/boost/inc.hpp"
# include "behaviac/base/meta/boost/cat.hpp"
# include "behaviac/base/meta/boost/comma_if.hpp"
# include "behaviac/base/meta/boost/repeat.hpp"

# include "behaviac/base/meta/boost/enum_binary_params.hpp"

# define BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(count, param, def) BOOST_PP_ENUM_BINARY_PARAMS(count, param, = def BOOST_PP_INTERCEPT)

/* BOOST_PP_ENUM_SHIFTED_PARAMS */
#define BOOST_PP_ENUM_SHIFTED_PARAMS(count, param) BOOST_PP_REPEAT(BOOST_PP_DEC(count), BOOST_PP_ENUM_SHIFTED_PARAMS_M, param)

#define BOOST_PP_ENUM_SHIFTED_PARAMS_M(z, n, param) BOOST_PP_COMMA_IF(n) BOOST_PP_CAT(param, BOOST_PP_INC(n))

# endif
