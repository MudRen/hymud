//fuzhai_dating.c ����
//Hydra

inherit ROOM;

void create()
{
    set("short","����");
    set("long", @LONG
��������Ա��ҵĿ��������ܵ�ǽ�Ϲ����˸�ʽ�ֻ���������ǽ�����ż���
���ӣ�����ǽ�߷���һ�����ӡ�������Ա�����ƺ�ʩ�������ݳ��������������
�Բ��������ݰ��յ�����������æ����һ��Ҳ�����ڰ�������������Ӵ����õ�
���ա�
LONG
    );
    
    set("exits", ([ 
        "south"         :       __DIR__"fuzhai1",
        "east"         :       __DIR__"fuzhai_zoulang1",
    ]) );
    set("objects",([
        __DIR__"npc/zhang"      :   1,
    ]) );

        setup();
}

