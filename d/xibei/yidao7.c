inherit ROOM;
void create()
{
    set("short","���");
    set("long",@LONG
���бƽ��߾���פ�����ࣻ����������ȥ����Ұ֮�о�կ���Ǳ������岼��
��ʱ��һ�Ӷӹپ�������¤Ѳ�ߡ���һ��������٣�ֻ�ھ���֮��������ũ
�һЩС��ׯ��ɢ��䡣ÿ����կ���ܻ��йپ����ѵľ��͡�������һƬ��ɽ
���롣
LONG);
    set("exits",([
        "east"   : __DIR__"yidao6",
        "west"  : __DIR__"yidao8",
    ]));
 set("outdoors","xibei");
    setup();
}

