#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "�ɻ�԰"); 
        set("long", @long
һ��ׯ԰������е����ɻ�������һ����ÿ��ʢ�ģ��ǡ����������Ⱦ��
�ĺɻ�����Ҷ�򸡻��������ܲ�㣬������̣������������ס��ۡ��졢��졢
������ɫ��Ȼ����ֵ���������̣�΢��������������磬�����˿��⡣
����ͣ����һҶ����С�ۡ�
long); 
        set("type","waterbody");
        set("exits",([
                "south":__DIR__"men",
                "west":__DIR__"shulin1",
                "east":__DIR__"shulin2",
        ]) );
       set("outdoors", "shanxi");
        set("item_desc", ([
                "boat": "һҶС�ۣ������ʻ����ں���ƮƮ������\n",
                "С��": "һҶС�ۣ������ʻ����ں���ƮƮ������\n",
                "lake": "��ˮ�峺��������������У�ϴ������Ľ�������(swim)��\n",
                "�ɻ���": "��ˮ�峺��������������У�ϴ������Ľ�������(swim)��\n",
                "����": "�����밶�������ɣ��Ṧ�õĻ�����һԾ����(charge)��\n",
                "center": "�����밶�������ɣ��Ṧ�õĻ�����һԾ����(charge)��\n",

        ]) );
        set("coor/x",-500);
        set("coor/y",-370);
        set("coor/z",100);
        setup();
} 
void init(){ 
        add_action("do_swim", "swim");
        add_action("do_charge", "charge"); 
}   
int do_charge(string arg)


{
        object room;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ����������\n");

                return 1;
        }
        if( arg == "����" || arg == "center" )
        {
                me = this_player();
                if ( me->is_busy() )
                        return notify_fail("������æ�úܣ������ƶ���\n");
            if ( me->query_skill("dodge") >= 100 )
                {
                        message_vision("$N����һ�ţ�����С�ۣ�ʻ����Ľ��......\n", me);
                        room = find_object(__DIR__"zhubaoge");
                        if(!objectp(room)) room = load_object(__DIR__"zhubaoge");
                        me->move(room);
                        message_vision("$N���ɵ�����С���ϡ�\n", me);
                        return 1;
                }
                else
                {
                        message_vision(HIY"$N����ƨ�ɣ�����������׼������ķ�Ծ��\n"NOR, me);
                        message_vision(HIY"$N���ܼ�����ͻȻ����ѽ����һ������ɫ�԰׵�ͣ�ں��ߡ�\n"NOR, me);
                        me->start_busy(3);
                        return 1;
                }                       
        }
        else
        {
                write("�㲻����Ծ��"+arg+"\n");
                return 1;
        }
} 
int do_swim(string arg)
{
        object room;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ�������Σ�\n");
                return 1;
        }
        if( arg == "�ɻ���" || arg == "lake" )

        {
                me = this_player();
                if ( me->is_busy() )
                        return notify_fail("������æ�úܣ������ƶ���\n");
                if ( random(100) > 5 )
                {
                        message_vision(HIY"$N�����Ϸˮ�����������Ծ����С�\n"NOR, me);
                        message_vision(HIY"$NͻȻ������Щ�����Ķ�������....��$N��æ����һ���һ����λذ��ߡ�\n"NOR, me);
                        me->start_busy(2);
                        return 1;
                }
                else
                {
                        message_vision(HIY"$N�߸�Ծ�𣬰����һ��ת�ۣ����������壬ֱ����С�\n"NOR, me);
                        message_vision(HIY"��ˮˮλͻȻ�½���$Nһͷ����������ʯ�ϡ�\n"NOR, me);
                        me->start_busy(3);
                        me->unconcious();
                        return 1;
                }                       
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}
