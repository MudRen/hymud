 // teapot.c
inherit ITEM;
inherit F_LIQUID; 
void create()
{
        set_name("������", ({ "cha zi zhou", "zhou" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�벻֪��ʲô�����࣬Ũ������ζ������ʳ��������\n");
                set("unit", "��");
                set("value", 30);
                set("max_liquid", 10);
        } 
        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "name": "������",
                "remaining": 10,
        ]) );
        
}       
