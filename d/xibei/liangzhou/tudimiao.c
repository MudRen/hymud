//tudimiao.c

inherit ROOM;

void create()
{
    set("short","������");
    set("long", @LONG
һ���ƾɵ��������������ʧ�ޣ��Ѿ����Ʋ����ˡ�����ſ�ǽ��������
��һ������������ǰ��Ĺ������沼���˻ҳ����������������ʢ������֪Ϊʲ
ô�⼸��˥�����������������������ؤ�ܷ�ȡů�ĵط��ˡ�
LONG
    );
    set("exits", ([ 
        "north"         :       __DIR__ "lroad1",
    ]) );
        
    set("objects",([
        __DIR__"npc/beggar"     :   1,
    ]) );
        
    setup();
}

