class Solution {
    static int ans = 0;

    public static boolean isValid( List<Integer> special, List<Integer> needs ){
        for ( int i = 0; i < needs.size(); i++ ){
            if ( needs.get(i) < special.get(i) )
                return false ;
        }
        return true ;
    }

    public static int directBuy( List<Integer> price, List<Integer> needs ){
        int value = 0;
        for ( int i = 0; i < price.size(); i++ ){
            value += price.get(i)*needs.get(i) ;
        }
        return value ;
    }

    public static void helper( List<Integer> price, List<List<Integer>> special, List<Integer> needs, int money, int index ){

        if ( money > ans){
            return ;
        }
        if ( index == -1 )
        {
            money += directBuy(price,needs) ;
            if ( money < ans )
                ans = money ;
            return ;
        }        

        helper( price, special, needs, money, index-1 ) ;

        List<Integer> offer = special.get(index) ;
        if ( isValid( special.get(index), needs ) == true )
        {
            int n = needs.size() ;
            List<Integer> newNeeds = new ArrayList<>() ;

            for ( int i = 0; i < needs.size(); i++ ){
                int x = needs.get(i) - offer.get(i) ;
                newNeeds.add(x) ;
            }
            helper( price, special, newNeeds, money + offer.get(n), index ) ;
        }
    }
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        ans = directBuy(price,needs) ;
        helper( price, special, needs, 0, special.size()-1 ) ;
        return ans ;
    }
}
