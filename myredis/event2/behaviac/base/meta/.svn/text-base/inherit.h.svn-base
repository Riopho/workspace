





#ifndef _BEHAVIAC_REAL_BASETYPE_COMPOSE_H__INCLUDED
#define _BEHAVIAC_REAL_BASETYPE_COMPOSE_H__INCLUDED

#include "behaviac/base/meta/collection.h"

namespace behaviac
{
    namespace Meta
    {
        namespace Details
        {
            Inherit Implementation forward declaration
            template <   typename SequenceType,
                     template< typename Type, typename BaseType > class NodeType,
                     typename RootType = Empty >
            struct InheritImpl;

        }    namespace Details


                /// Inherit utility
                ///
                /// based on Boost::mpl::inherit
                ///
                /// Use this utility to create linear class hierarchy. You need to provide
                /// a list of type defined with the help of Type::Collection tool. Next, a node
                /// class containing two template parameters. The first parameter is the
                /// current Type (from those specified in Type::Collection). The second is the
                /// current base class that you must derived from. Finally, a Root class
                /// that is going to be the top class in the hierarchy.
                ///
                /// Ex:
                ///
                /// template< typename Type, typename Base >
                /// class Node : public Base
                /// {
                ///     virtual void Fun( Type * ) = 0;
                /// };
                ///
                /// class Root {};
                ///
                /// typedef typename Type::Collection< int, short, ( etc... ) > List;
                ///
                /// typedef Type::Inherit< List, Node, Root >::Result GeneratedClass;
                ///
                /// --------
                /// | Root |
                /// --------
                ///    ^
                ///    |
                /// ----------------------------------
                /// | Node< long, Root >             |
                /// |---------------------------------
                /// | virtual void Fun( long * ) = 0;|
                /// ----------------------------------
                ///    ^
                ///    |
                /// -----------------------------------------------------
                /// | InheritImpl< Sequence< long, Null >, Node, Root > |
                /// -----------------------------------------------------
                ///   ^
                ///   |
                /// --------------------------------------------------------------------
                /// | Node< short, InheritImpl< Sequence< long, Null >, Node, Root > > |
                /// |-------------------------------------------------------------------
                /// | virtual void Fun( short * ) = 0;                                 |
                /// --------------------------------------------------------------------
                ///    ^
                ///    |
                /// ------------
                /// | (etc...) |
                /// ------------
                ///    ^
                ///    |
                /// ------------------
                /// | GeneratedClass |
                /// ------------------

                template <   typename VectorType,
                template< typename Type, typename BaseType > class NodeType,
                typename RootType = Empty >
        struct Inherit
        {
            typedef typename VectorType::Type SequenceType;
            typedef typename Details::InheritImpl< SequenceType, NodeType, RootType > Result;
        };

        template <   template< typename Type, typename BaseType > class NodeType,
                 typename RootType >
        struct Inherit< Null, NodeType, RootType >
        {
            typedef RootType Result;
        };
    }
}

#include "behaviac/base/meta/inherit.hpp"

#endif
