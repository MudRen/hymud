#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "���Ϲ�������"); 
        set("long", @LONG
����������Ϲ�������꣬��Ȼ�Ĵ����ǻ���δȥ���͹����ա����Ƕ��е���
Ѽ��ζ���㼸������������ȴһ�У������߻��м������Ҳ�����Ϲ�˯���ĵط���
��䷿�����ǹ��ŵģ���Ϊ���Ϲ������±ζҲ�ǡ������ط��������Ǳ�����͵͵
ѧȥ�ˣ����ķ���Ҳ�������ˡ�
LONG); 
        set("type","house");
        set("exits",([
                "east":__DIR__"xiaojie3",
                "west":__DIR__"neishi",
        ]) );
        set("objects",([
                __DIR__"npc/mai":1,
        ]) ); 
        set("coor/x",-590);
        set("coor/y",100);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_look", "look");
} 
int valid_leave(object me, string dir)
{
        if( userp(me) && dir=="west" && present("mai laoguang", this_object()) ) 
                return notify_fail("���Ϲ�����Ц��������������ϵ����ϵ�ͣ�����ϵ��ȥ�ġ���\n");
        return 1;
} 
int show_notify(object obj, int i)
{
        object me;
        object room, mai;
        object feng;
        me = this_player();
   mai = present("mai laoguang", environment(me));
   	if(mai)
        if (mai->is_fighting())
        {
                return notify_fail("���Ϲ����ڴ�ܣ�û�������㣡��\n");
        }
        else
        {
                if (!me->query_temp("yaopai")) {
                        message_vision("���Ϲ�պ�Ц����������$N������ҡ��ҡͷ��\n",me);
                        return 1;
                }
                if (!(room=find_object(__DIR__"neishi")))
                        room=load_object(__DIR__"neishi");
                write(HIY"���Ϲ���ɫͻȻ��úܽ��š�\n"NOR);
                write(HIY"���Ϲ���㲻ע�⣬͵͵Ų�����ݡ�\n"NOR);
                destruct(mai);
                feng = new(__DIR__"npc/feng");
                feng->move(room);
                me->set_temp("fugui_mai_showyaopai",1);
                return 1;
        }
} 
int do_look(string arg)
{
        object  me;
        me = this_player();
        if( arg == "west") 
        {
                tell_object(me,"��ߺ�����ģ�ʲô����������\n"); 
                return 1;
        }
        return 0;
}
