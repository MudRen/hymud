// /d/map/zhongyuan/yilou_he.c
// by lala&lnwm, 1997-12-11
inherit ROOM;

void create()
{   
    set("short","��¦�ӱ�");
    set("long",@LONG
ԭ���������ڳ����ߵģ��������ڳ������������ٻ�����ʹ�������ƣ�����
���ݾ�Զ�볤���ˡ����Ƴ����ڿ�Ԫ��ʮ�����ʱ�����ݴ�ʷ��嫿���¦�Ӷ�
ʮ�����ʹ��ܴӹ���ֱ�����ӡ�ʫ�������Ϊ�˸�ʫһ�ף�

    �빫���ºӣ�������������Ṧ�����ˣ����ͬ����
        
LONG );
    set("exits",([
        "north"     : __DIR__"yunhe4",
//        "south"     : __DIR__"yilou_he",
//      "southwest" :
    ]));                    
    set("outdoors","zhongyuan");
    setup();
}

