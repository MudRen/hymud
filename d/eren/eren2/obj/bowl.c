 inherit ITEM;
inherit F_LIQUID; 
void create()
{
        set_name("����໨��", ({ "bowl"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������໨�롣\n");
                set("unit", "��");
                set("value", 30);
                set("max_liquid", 10);
        } 
        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "name": "������÷��",
                "remaining": 10,
        ]) );
        
}    
