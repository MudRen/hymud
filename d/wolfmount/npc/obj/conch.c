#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIC"��"HIB"��"HIG"��"HIY"��"NOR,({ "conch shell","conch","shell" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("long", "һ���������磬�߲ʰ�쵵ĺ��ݣ�����Դ������£̣ϣף�����\n");
        }
        
} 
void init()
{
        add_action("do_blow", "blow");
} 
int do_blow(string arg)
{
        if( arg != "conch" && arg != "shell" && arg != "conch shell" ) return 0;
        if ( this_player()->query("neili") < 50 )
        {
                message_vision("$N�������㣬���ܴ�"+ this_object()->name() + "��\n" , this_player() );
                return 1;
        }
        else if ( this_player()->query("neili") < 40 )
        {
                message_vision("$N���������ӣ����Ų��Ӵ���"+ this_object()->name() + "����ʲô����Ҳû�С�\n" , this_player() );
                return 1;
        }
        else
        {
                message_vision("$N���ᴵ����" + this_object()->name() + "����ʱ���ཡ����졣��\n", this_player() );
                this_player()->add("force",-40);
                this_player()->start_busy(3);
                environment(this_player())->conch_notify();
                return 1;
        }       
}
