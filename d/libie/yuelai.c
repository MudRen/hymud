 // Room: yuelai.c --- by MapMaker
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "������ջ"); 
        set("long", @LONG
������С�س������Ŀ�ջ�ˣ�����Ҳ���¸ǵģ���ǰ����ȴ
ͻȻ�������������Ӱ�¥�ϵ��׼�����װ����һ�顣��ջ�ϰ�Ҳ��
����ʾ�ܲ����͡�˽�����ϰ�͸����Ϣ˵��һ�н�������Ϊ��Ϯһ
�Ⱥ������С��үҪ��¥���¸ǵġ������סһ���ϡ�
LONG); 
        set("type","house");
        set("exits",([
        "up":__DIR__"corrider",
        "north":__DIR__"stoneroad2",
        ]) ); 
        set("objects", ([
                __DIR__"npc/owner": 1 ]) ); 
        set("indoors", "libie");
        set("coor/x",40);
        set("coor/y",190);
        set("coor/z",0); 
        setup();
} 
int valid_enter(object me)
{
        object ob,cloth;
        
        if (ob=present("lao ban", this_object()))
        if (!me->query("marks/���") && me->query("libie/��𹳶�")&&me->query("libie/���_С���ӵľ���")&&me->query("libie/ĥ������"))
        ob->start_call_out( (: call_other, __FILE__, "owner_leave" ,me,ob:), 1);
        return 1;
}
        
                
         
int valid_leave(object me, string dir)
{
    object ob,cloth;
        if( dir == "up" && ob=present("lao ban", this_object()))
        {
                cloth=present("waiter cloth",me);
                if(objectp(cloth))
                if(cloth->query("equipped"))
                        return 1;
                
                        
         return notify_fail("�ϰ�˫��һ�ŵ�סȥ·�������������" + RANK_D->query_rude(this_player()) + "��������˰������˵�С��ү�ǻ��˵ã�\n");
        }
        return 1;
} 
int owner_leave(object me, object owner)
{
        if (!present(me,this_object())) return 0;
        
        
    message_vision(YEL "��ջ�ϰ�̽ͷ���������⣬���ͷ��ĵ�����ĥ����ͷ���Ƿ���ĥ������
�������ŵ�С��ү���ɵ������𡣷ǵø����߲��ɡ�\n��һ˵�꣬�ϰ��һ������˳�ȥ��\n"NOR,me);
        destruct(owner);
        me->set_temp("libie/���_����ֿ�ʼ",1);
        return 1;
}      
