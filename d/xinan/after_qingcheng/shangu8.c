//writen by lnwm
//shangu8.c

inherit ROOM;
void create()
{
    set("short", "�Ĵ�����ɽ��");
    set("long", @LONG
�Ĵ������ĳ�ɽ����֮��.���ܵ�ɽ�߸ߵ͵�,�е����ͻ��.�е��ת�ͻ�.
��ɽ���ǲ�ľ��ʢ,���۶����ޱߵ���ɫ.ż����ɽ�����Բ��ɽ�������Ѷ���
ˮ�����������������,Ȼ�����������ޱߵ���ɫ֮��.����ˮ��ɽɫ�����ζ�
��,����֪��������ʧ��������.
LONG
        );
    set("exits", ([ 
		"east"      :       __DIR__ "shangu1",
        "west"      :       __DIR__ "shangu1", 
        "north"     :       __DIR__ "shangu2",
        "south"     :       __DIR__ "outshangu",
        "southwest" :       __DIR__ "shangu2",
        "northeast" :       __DIR__ "shangu4",  
	]));
    set("outdoors","lnwm");
    setup();
}
