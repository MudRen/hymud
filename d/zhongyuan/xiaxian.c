// xiaxian.c
inherit ROOM;

void create()
{   
    set("short","����");
    set("long",@LONG
�����ϱ�Ҳ��һ������ɽ�����ذ��ն���Ϊ���ġ������������ﲻʳ������
���ġ����Ҳ�������ؼ��ݣ�����͹��е�����ɽ�������ĸ����棬����֪����
���Զ���ũ��������С���Ͳˡ������ȵȡ���ɽ�����м�����ׯԺ����ǽ
���ߣ���Ϊ���ɡ�
LONG );
    set("exits",([
        "southwest" : __DIR__"zhongtiao_shan3",
        "north" : __DIR__"jiangxian"  ]) );
    set("outdoors","zhongyuan");
    setup();
}
