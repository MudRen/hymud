inherit ROOM;
void create()
{
    set("short","���");
    set("long",@LONG
�������ݣ�������ݵؽ磬�ϲ��ĳ�ɽ��������������ߡ�ɽ�ж��ס����
ެ��������ʱ��ɽɧ��������ׯ����ɽ��ȥ������ެ��������ȥ���������Ǳ�
���������Ǵ�Ƭ�������ɢ����һЩ��ׯ�;�կ��
LONG);
    set("exits",([
        "east"   : __DIR__"qinzhou_fu",
        "northwest"  : __DIR__"yidao4",
    ]));
 set("outdoors","xibei");
    setup();
}

