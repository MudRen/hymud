#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "����");
        set("long", @LONG
����һ������ĵض������ڳ�ʪ���ֹ⻬����ű��������Ѿ�����
��ʬ�巢���̱ǵ���ζ���Ա��ƺ����м�ֻ��������ںڰ��п�����
�㣬�·��ڵ��Ž�����Ϊ��һ�����͡�������ȥ��һ��������ס��Ψ
һ�ĳ��ڣ���������һ�����������С�ף�Ͷ�¼�˿�谵�ĵƹ⡣
LONG);
        set("indoors", "eren2");
        set("no_magic",1);
        set("item_desc", ([
                "����": "һ������ٽ��ص����壬�������ǲ������ƿ��ģ������뷨���ҳ�·�ɡ�\n",
                "tieban": "һ������ٽ��ص����壬�������ǲ������ƿ��ģ������뷨���ҳ�·�ɡ�\n",
        ]) );
        set("objects", ([
                __DIR__"npc/rat1" : 1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{       
        add_action("do_climb", "climb");
}  
int do_climb(string arg)
{
    object obj, me;
    int kar;
    
    if(!arg || arg=="") return notify_fail("��Ҫ����������\n");
    me = this_player();
    if( arg == "wall" || arg == "����" || arg == "up")
    {
        if( me->is_busy() )
            return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
        message_vision(YEL"$Nʹ�����̵�������˳�Ŷ���������ȥ��\n"NOR, me);
        message_vision(YEL"$N�����������������壬������˿�������������������˴������
����ֻ�����ҳ�·�ˡ�\n"NOR,me);
        me->start_busy(1);
        return 1;
    }
    return notify_fail("�㲻������"+arg+"��\n");
}             
