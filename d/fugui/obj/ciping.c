 inherit ITEM;
inherit F_LIQUID; 
void create()
{
        set_name("���ƿ", ({ "ping", "ƿ" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ƿ��\n");
                set("unit", "��");
                set("value", 1000);
                set("max_liquid", 1);
        } 
        set("liquid", ([
                "type": "water",
                "name": "��ҩ",
                "remaining": 1,
                "drunk_apply": 10,
        ]) );
        
} 
void init()
{
        add_action("do_drink","drink");
} 
int do_drink(string arg)
{
    if(arg=="ping" || arg=="���ƿ") {
   if (this_object()->query("liquid/name")=="��ҩ")
   {
        object me;
        me=this_player();
        message_vision("$N�����ƿ��Ľ�ҩһ��������ȥ��\n",me);
        me->clear_condition("redsnake");
        me->unconcious();
        destruct(this_object());
        return 1;
   }
 }
}     
