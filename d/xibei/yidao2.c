inherit ROOM;
void create()
{
    set("short","���");
    set("long",@LONG
μ�����ε�ˮ�������һ��������ũ���Ұ������Ÿ����͹��ӣ�һ����
������������ߵ�һƬ��졣�����������ݵؽ磬�ǹ���һ���˿ڳ��ܣ��ز���
�ĵı��ء��ϱ���������ϵ��������ɽ������Զ��������һ��Ⱥɽ��
LONG);
    set("exits",([
        "east"   : __DIR__"yidao1",
        "west"  : __DIR__"qinzhou_fu",
    ]));
 set("outdoors","xibei");
    setup();
}

