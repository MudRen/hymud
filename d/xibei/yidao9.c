inherit ROOM;
void create()
{
    set("short","���");
    set("long",@LONG
���бƽ��߾���פ�����ࣻ����������ȥ����Ұ֮�о�կ���Ǳ������岼��
��ʱ��һ�Ӷӹپ�������¤Ѳ�ߡ���һ��������٣�ֻ�ھ���֮��������ũ
�һЩС��ׯ��ɢ��䡣ÿ����կ���ܻ��йپ����ѵľ��͡�������һƬ��ɽ
���롣������һ���Ǳ���
LONG);
    set("exits",([
        "east"   : __DIR__"yidao8",
        "west"  : __DIR__"dingxi_cheng",
    ]));
 set("outdoors","xibei");
    setup();
}

