inherit ROOM;
void create()
{
    set("short","���");
    set("long",@LONG
μ�����ε�ˮ�������һ��������ũ���Ұ������Ÿ����͹��ӣ�һ����
������������ߵ�һƬ��졣��ȥ�����ǹ���һ���˿ڳ��ܣ��ز����ĵı��ء�
�ϱ���������ϵ��������ɽ������Զ��������һ��Ⱥɽ��
LONG);
    set("exits",([
     "east" : "/d/zhongyuan/guandao1",
        "west"  : __DIR__"yidao2",
    ]));
 set("outdoors","xibei");
    setup(); 
}

