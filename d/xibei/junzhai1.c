inherit ROOM;
void create()
{
    set("short","��կ");
    set("long",@LONG
������һ�����կ����Χ�Ծ�ľ��ǽ����Բ����һ�����ɼ����ʣ�ľ��
���þ�Ȼ����һ�Ӷ�����ڿճ��ϴ�����կ����һƬ�����أ�����ƥ������կ
��С�ӱ���ˮ���Բݡ�һ�������կ���������������졣
LONG);
    set("exits",([
        "east"   : __DIR__"tuntian2",
        "north"  : __DIR__"tuntian3",
    ]));
 set("outdoors","xibei");
    setup();
}

