





namespace behaviac
{
    namespace Meta
    {
        namespace Details
        {
            Template recursion take place here
            template <   typename HeadType,
                     typename TailType,
                     template< typename, typename > class NodeType,
                     typename RootType >
            struct InheritImpl< Sequence< HeadType, TailType >, NodeType, RootType > : public NodeType< HeadType, InheritImpl< TailType, NodeType, RootType > >
            {};

            template <   typename Type,
                     template< typename, typename > class NodeType,
                     typename RootType >
            struct InheritImpl< Sequence< Type, Null >, NodeType, RootType > : public NodeType< Type, RootType >
            {};

            template <   template< typename, typename > class NodeType,
                     typename RootType >
            struct InheritImpl< Null, NodeType, RootType > : public RootType
            {};
        }
    }
}
