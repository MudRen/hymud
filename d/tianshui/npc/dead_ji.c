// dead_ji.c

inherit ITEM;

void create()
{
        set_name("����", ({ "dead ji", "ji" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "һֻ���˵���ĸ�����Դ������������һ�ߡ�");
                set("value", 50);
        }
        call_out("decay", 180);
}
protected void decay()
{
        message_vision("$N����һ�����ŵĶ�����õ��� ... \n",this_object());
        destruct(this_object());
}
