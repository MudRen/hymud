#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("����һ������", ({ "letter", "��"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                                set("long",
"���Ƿ������ˮ��Ѫˮ��ţƤ�ţ��Ի����ڡ��ƺ�����˺��(tear)�����飺
      ���� ��һ�� ��������"NOR);
        }
        
} 
void init()
{
  if(this_player()==environment()){
        add_action("do_tear","tear"); 
        }
} 
int do_tear(string arg)
{
        object          me, ob;
        if(  arg != "letter" )
                return 0;
        me = this_player();
        ob = this_object();
        message_vision("$N��$n�ķ��˺����ȡ�������е��ż�\n", me, ob);
        set_name("��˺������", ({ "letter", "��"}) );
        set("long","һ���Ѿ����˷���ŷ⣬������ż���д�ţ�\n
        �������� ��
    ÷����Ϫһս���˴���һ֫�����Ϊ���ø��𣻺�ĥ�����˸�֪ʵ�飬���޿ɵ�����
֮���壬��ɽ��ֹ���ȥ��ɱ���������롣���ɣ��ضϱ��Ա�����\n");
        remove_action("do_tear","tear");
        if(ob->query("������")==me)
        {
                me->set("marks/���","ʧ��");
           me->add("score",-2000);
        }
        return 1;
}      
