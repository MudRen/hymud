inherit ROOM;
void create()
{
    set("short","���");
    set("long",@LONG
�������ݣ�������ݵؽ磬�ϲ��ĳ�ɽ��������������ߡ�ɽ�ж��ס����
ެ��������ʱ��ɽɧ��������ׯ����ɽ��ȥ������ެ��������ȥ�İٶ�����Ǳ�
���������Ǵ�Ƭ�������ɢ����һЩ��ׯ�;�կ��
LONG);
    set("exits",([
        "southeast"   : __DIR__"yidao3",
        "west"  : __DIR__"yidao5",
    ]));
 set("outdoors","xibei");
    setup();
}

