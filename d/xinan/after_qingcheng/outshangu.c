//writen by lnwm
//outshangu.c

inherit ROOM;
void create()
{
    set("short", "�Ĵ�����ɽ��");
    set("long", @LONG
�Ĵ������ĳ�ɽ����֮��.���ܵ�ɽ�߸ߵ͵�,�е����ͻ��.�е��ת�ͻ�.
��ɽ���ǲ�ľ��ʢ,���۶����ޱߵ���ɫ.ż����ɽ�����Բ��ɽ�������Ѷ���
ˮ�����������������,Ȼ�����������ޱߵ���ɫ֮��.����ˮ��ɽɫ�����ζ�
��.
LONG
        );
    set("exits", ([ 
		"east"      :       __DIR__ "shangu8",
	    "west"      :       __DIR__ "gudi",
    ]));
    set("outdoors","lnwm");
    setup();
}
