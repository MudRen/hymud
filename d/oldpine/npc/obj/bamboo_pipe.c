 // bamboo_pipe.c
inherit ITEM; 
void create()
{
        set_name("���",({ "bamboo pipe", "pipe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "bamboo");
                set("long", "һ��Լ���߶೤����ܣ������������С�ף�Ҳ������������ࣿ\n");
        }
} 
void init()
{
        add_action("do_play", ({ "play", "blow" }) );
} 
int do_play(string arg)
{
        if( !id(arg) ) return 0; 
        message_vision("$N����һ��" + name() + "���ཱུش���������\n",
                this_player() );
        environment(this_player())->pipe_notify(); 
        return 1;
}
