 inherit ITEM;
void create()
{
        set_name("镜子", ({ "mirror", "镜子"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("prep", "on");
                set("long", "一面炫目的镜子，镜子後面有些文字。\n");
                set("value", 1);
                set("skill", ([
                        "name":         "kongshoudao",        
                        "exp_required": 100,              
                        "jing_cost":     100,     
                        "difficulty":   100,     
                        "max_skill":    100              
                ]) );
        }
    
} 
int is_container() { return 1; }     
