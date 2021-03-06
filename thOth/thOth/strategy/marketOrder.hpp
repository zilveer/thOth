#ifndef thoth_market_order_hpp
#define thoth_market_order_hpp

#include <thOth/strategy.hpp>
#include <thOth/time/timeSeries.hpp>
#include <thOth/relinkableHandle.hpp>
#include <thOth/quote/quote.hpp>

namespace thOth {

	// Hit the market and get executed 
	// at the current market level
	class marketOrder : public strategy {

	public:

		marketOrder();									// default constructor
		marketOrder(const marketOrder &);				// copy constructor

		marketOrder(const dateTime &,					// value constructor
					const volume &,
					const marketSide &);

		~marketOrder();									// destructor
		marketOrder & operator=(const marketOrder &);	// assignement operator

		virtual dateTime date() const;					// returns the implementation date
		
		void performCalculations();						// lazyObject Interface

	protected:

		// TS handle
		thOth::relinkableHandle<thOth::timeSeries<thOth::dateTime, thOth::quote> > ts_;

	};

}

#endif
