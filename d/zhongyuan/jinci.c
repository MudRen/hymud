// jinci.c
inherit ROOM;

void create()
{   
    set("short","����");
    set("long",@LONG
�����Ѿ���̫ԭ����Ͻ���ˡ�·����һ����ǽ��Ժ��Ժǰľդ�����߰��ű�
��ִ�£�Ժ�ŵ����߸�һͷ��ʯʨ�ӣ��������������һ���ֽ���ң����顰��
�������������֡�����ǽ������Ǽ���������֮�ܣ�����ʼ�����ݶ����ġ�
LONG );
    set("exits",([
        "southwest": __DIR__"fenhe_gudi8",
        "northeast" : __DIR__"jinyang_chengxia"  ]) );
    set("outdoors","zhongyuan");
    setup();
}
