inherit ROOM;
void create()
{
        set("short", "�����Ż���");
        set("long",
"�������ߡ���ʮ�����ȣ��໥���������಻����ֱ�������޾���ÿ��\n"
"����ת�䴦����һյ�������ҡ�β����ĻƵơ��ȱߵ�̶ˮ�ڵƹ�����\n"
"�·���ī�̵���⡣\n"
);
        set("no_magic", "1");

        setup();
}
int valid_leave(object me, string dir)
{
     if(random(me->query("kar")) > 27 ) {
     message_vision("ֻ���ذ�֨ѽѽ������󣬵ذ�ͻȻ����������$Nһ�µ��˽�ȥ��\n", me);
     me->move("/d/llszhuang/didao");
     return notify_fail("");}
     return ::valid_leave(me, dir);
}

