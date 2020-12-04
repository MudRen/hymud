#include <ansi.h>
inherit ROOM;
string look_book();
void create()
{
        set("short","��ϼ��");
        set("long",
"�������ճ���ӵĵط�����ʰ��һ����Ⱦ��������Ϊ���£���˵����\n"
"��ׯ���İ�ϰ�䣬����ǽ�Ϲ��ŵĶ�ҩ�Һ͵�ǹ�Ϳ���֪���������ĵط�\n"
"��һ����ױ̨������ǰ����һ����������(Book)������һ�����ι�״����\n"
"�̷����Աߣ�Ҳ����ʲô�Źֻ��ء�\n"
);
        set("no_magic", "1");

        set("exits", ([ /* sizeof() == 2 */
          "south" : __DIR__"hall",
        ]));
        set("seed1",random(10)+1);
        set("seed2",random(20)+21);
        set("seed3",random(50)+51);
        set("seed4",random(100)+101);

      set("item_desc", ([
                "shu": (: look_book :),
                "book": (: look_book :),
                "��": (: look_book :),
        ]) );

        setup();
}

int init()
{
        add_action("do_turn","turn");
}

string look_book()
{
        string result;
        object me;
        int puzzle;

        me = this_player();
        result = "\n�Ȿ����û��ʲôֵ��ע��Ķ�����\n";
        if( puzzle = me->query_temp("marks/xanadu_hall2") )
        {
                me->set_temp("marks/xanadu_hall3",1);
              result += "������ʧ����Ҫ�������ʱ�����������һ������������д��: \n"
                          "�������̾���һ���ſ��Խ�ȥ��\n";
                result += "���ˣ����У����̵������Ҫ������...\n";
                result += "�����������"+query("seed1")+"��"+puzzle%query("seed1")+"��";
                result += "����"+query("seed2")+"��"+puzzle%query("seed2")+"��";
                result += "����"+query("seed3")+"��"+puzzle%query("seed3")+"��";
                result += "����"+query("seed4")+"��"+puzzle%query("seed4")+"\n";
                result += "Ȼ����һ��(turn)��µ������֣�������ʲô���֡�\n";
        }
        return result;
}

int do_turn(string arg)
{
        object me;
        int answer,puzzle;

        me = this_player();
        if(!arg)
                return notify_fail("��Ҫ������ת����һ�������ϣ�\n");
        if( me->query("neili") < 500 )
                return notify_fail("����������������������̡�\n");
        if( !(answer = (int)arg) || !(me->query_temp("marks/xanadu_hall3")) )
              return notify_fail("��Ϲתʲô��\n");
        me->add("neili",-150);
        message_vision("$N�����̲�����"+arg+"��λ��\n",me);
        puzzle = (int)me->query_temp("marks/xanadu_hall2");
        if( ("X"+puzzle+"X") == ("X"+answer+"X") )
        {
                write("һ�����֮�����֮����������һ���µĵط���\n");
                me->delete_temp("marks/xanadu_hall2");
                me->delete_temp("marks/xanadu_hall3");
                me->move(__DIR__"lou0");
                tell_room(this_object(),"ǽ��ͻȻ����һ���ţ�"+me->query("name")
+"������ԥ�����˽�ȥ��\n");
        }
        else
                message_vision("����ʲô��û�з�����\n",me);
        return 1;
}

