// /d/map/zhongyuan/yunhe3.c
// by lala, 1997-12-11
inherit ROOM;

void create()
{   
    set("short","����˺ӱ�");
    set("long",@LONG
����˺��ƹ����ݣ��������򳤽��������ϴ�С��ֻ����������һƬ������
�󡣰����������磬�ഫ��Щ��������쾵�������ҽ�����ʱ�����ֵģ������
��Ϊ�������������˺������ϣ������˺�ͬ��¦�ӽ�������ӽ�
LONG );
    set("exits",([
        "north"     : __DIR__"yunhe2",
        "south"     : __DIR__"yunhe4",
    ]));                    
    set("outdoors","zhongyuan");
    setup();
}

