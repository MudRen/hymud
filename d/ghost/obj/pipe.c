 // pipe.c
inherit ITEM; 
void create()
{
        set_name("ͭ��",({ "pipe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("lore",1);
                set("material", "steel");
                set("long", "һ��Լ����೤��ͭ�ڡ�\n");
        }
        
} 
void init()
{
        add_action("do_blow", "blow");
} 
int do_blow(string arg)
{
          object me;
          me=this_player();
        if( arg != "pipe" ) return 0; 
        message_vision("$N����һ��" + this_object()->name() + "����һ����\n", this_player() );
           if(me->query("class")!="ghost"){
               environment(this_player())->pipe_notify(); 
               														}
        return 1;
}       
