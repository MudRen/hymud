#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "���ݾ�ͷ");
    set("long", @LONG
�����������ţ�һ�ȣ�door1��ͨ�����棬�ǻ�·������һ�ȣ�door2��������
·��������ǿ������׵�����̽�ģ�ֻҪһ��̤�£�����ٲ����ˣ�û����֪����
�������ǻ�·��������Լ�ѡ��ȥ���ţ���ֻҪһ�����ţ��ͷ��߳�ȥ���ɣ�����
����ˡ�
LONG
        );
    set("exits", ([ /* sizeof() == 0 */
        "down" : __DIR__"tianti3", 
        ]));
    set("item_desc", ([
        "door1":
        "�����ż�������ȫһģһ���ģ�û�����ܿ������Ĳ���������Ĳ��\n",
        "door2": 
        "�����ż�������ȫһģһ���ģ�û�����ܿ������Ĳ���������Ĳ��\n",
        ]) );
    set("coor/x",3310);
    set("coor/y",20);
    set("coor/z",20);
    setup();
} 
void init()
{
    add_action("do_open", "open");
    add_action("do_noregret", "noregret");
    add_action("do_say", "say");
    add_action("do_regret", "regret");
    remove_call_out("give_hint");
    call_out("give_hint",5,this_player());
} 
void give_hint(object who)
{
    if(present(who)) message_vision(HIY"
�����������ѡ���㲻���������һ�����������������˺���������ǡ�
����ѡ����������"NOR"\n",who);
}
                  
int do_open(string arg)
{
    if( arg == "door1" || arg == "door2")
    {
        message_vision(HIB"$N�ƿ����ţ�ʧ�������������Ԩ�����뿪�������� 
һɲ�Ǽ䣬$P����ǰ�ָ��ֳ����İ����˵�Ц��...  \n"NOR, this_player());
        this_player()->die();
        return 1;
    }
    return 0;
} 
int do_say(string arg)
{
    object room;
    if( arg == "�������������������" || arg == "�Ҿ�����ڣ�" ||
        arg == "I won't regret!" || arg == "����������ͨ�ˡ�"||
        arg == "����������㹻��")
    {
        message_vision(HIY "$N�����ƿ���һ���ţ���ǰ�ֳ������ޱȵ�Ϧ��... \n"
                      NOR, this_player());
        room = load_object(__DIR__"anbian1");
        this_player()->move(room);
        return 1;
    }
    return 0;
} 
int do_noregret(string arg)
{
    object room;
    tell_object(this_player(),HIW"�����Ҳ����ڵģ�����������������������Ѿ��㹻�ˡ�"NOR"\n");
    message_vision(HIY "$N�����ƿ���һ���ţ���ǰ�ֳ������ޱȵ�Ϧ��... \n"NOR,
                   this_player());
    room = load_object(__DIR__"anbian1");
    this_player()->move(room);
    return 1;
} 
int do_regret(string arg)
{
    tell_object(this_player(),HIW"��һ��ҪС�ģ��������ϻ���̫�������û�����ꡣ"NOR"\n");
    return 1;
}     
