//writen by lnwm
//entershangu.c

inherit ROOM;
void create()
{
    set("short", "���ɽ��");
    set("long", @LONG
��������ĳ�ɽ����֮��.���ܵ�ɽ�߸ߵ͵�,�е����ͻ��.�е��ת�ͻ�.
��ɽ���ǲ�ľ��ʢ,���۶����ޱߵ���ɫ.ż����ɽ�����Բ��ɽ�������Ѷ���
ˮ�����������������,Ȼ�����������ޱߵ���ɫ֮��.����ˮ��ɽɫ�����ζ�
��.
LONG
        );
    set("exits", ([ 
                "east"    :    __DIR__ "shan3",
        "southwest" :       __DIR__ "shangu1",
	]));
    set("outdoors","lnwm");
    setup();
}
