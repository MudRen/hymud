 inherit ITEM;
void create()
{
        set_name("高手入门", ({ "book" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        
"屡战屡败，屡败屡战，水滴石穿，铁杵成针。。。。。阿谈写于第五十六次重伤中。\n"
                );
                set("value", 260);
                set("material", "paper");
        }
        
}
     
