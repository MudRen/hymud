inherit ROOM;
void create()
{
    set("short","���");
    set("long",@LONG
����������ݵؽ磬�ϲ��ĳ�ɽ��������������ߡ�ɽ�ж��ס����ެ����
����ʱ��ɽɧ��������ׯ����ɽ��ȥ������ެ��������ȥ�İٶ�����Ǳ߾�����
���Ǵ�Ƭ�������ɢ����һЩ��ׯ�;�կ��
LONG);
    set("exits",([
        "east"   : __DIR__"yidao4",
        "west"  : __DIR__"yidao6",
    ]));
 set("outdoors","xibei");
    setup();
}

