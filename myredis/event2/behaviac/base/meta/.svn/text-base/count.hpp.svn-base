





namespace behaviac
{
    namespace Meta
    {
        namespace Details
        {
            template< typename LookingFor, typename HeadType, typename TailType >
            struct CountImpl
            {
                enum
                {
                    Result = CountImpl< LookingFor, typename TailType::Head, typename TailType::Tail >::Result
                };
            };

            template< typename LookingFor, typename TailType >
            struct CountImpl< LookingFor, LookingFor, TailType >
            {
                enum
                {
                    Result = 1 + CountImpl< LookingFor, typename TailType::Head, typename TailType::Tail >::Result
                };
            };

            template< typename LookingFor, typename HeadType >
            struct CountImpl< LookingFor, HeadType, Null >
            {
                enum
                {
                    Result = 0
                };
            };

            template< typename LookingFor >
            struct CountImpl< LookingFor, LookingFor, Null >
            {
                enum
                {
                    Result = 1
                };
            };

        }
    }
}
