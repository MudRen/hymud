 // An example book
inherit ITEM; 
void create()
{
        set_name("霸王枪谱" , ({ "bawang book","book"}) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本霸王枪王老爷子留下来的枪谱。\n");
        set("value", 500);
        set("skill", ([
                "name":                 "yuejia-qiang",      
                "exp_required": 1500000,       
                "jing_cost":             20,
                "difficulty":   15,  
                "max_skill":   150     
        ]) );
        
}
   
