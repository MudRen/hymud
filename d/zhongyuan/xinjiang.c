// xinjiang.c
inherit ROOM;

void create()
{   
    set("short","���");
    set("long",@LONG
����Ҳ���ǽ����Ĺ������뵱���Ĺ��ض������ķ�������إ�أ�ֱ�������
�ٲŵ��Ͼ�λ������ʩչ��ͼ���������������ϵ�����������ǿ�أ��ɾ�һ
����ҵ�����ղ�����һ���������ƣ��������ζ��ѡ�������ﻹ��ʲô�ǵĺۼ���
LONG );
    set("exits",([
        "south" : __DIR__"jiangxian",
        "northeast" : __DIR__"fenhe_gudi1"  ]) );
    set("outdoors","zhongyuan");
    setup();
}
