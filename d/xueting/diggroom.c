// Diggroom.c  edit by pian
// ������ʦ�Ĳο�
inherit ROOM;
void create()
{
	set("short", "�ɿ�");
	set("long", @LONG
ѩͤ������һ��С�͵Ĳɿ󳡣����ڸոտ����������������
�ܼ�ª�������������ɿ�Ȼ��ѩͤ���ϵĵ�����ȥ���ۣ���
��Ǯ�����������digg���вɿ󡣣�
LONG
        );
	set("exits", ([ /* sizeof() == 1 */
	"southwest" : __DIR__"work",
	"east" : __DIR__"diggroom2",
]));
	setup();
}
void init()
{
        add_action("do_digg", "digg");
}
int do_digg()
{
        object me,ob,*inv;
        int i,sk;
        me = this_player();
        sk = 10+random(250);
        sk = sk + sk;
        
        if(me->query("qi")<20)
        	return notify_fail("������������ˣ���������Ϣһ�°ɡ�\n");
        if(me->query("jing")<20)
        	return notify_fail("��ľ��������ˣ���������Ϣһ�°ɡ�\n");
        if(me->is_busy())
        	return notify_fail("������æ��\n");



        me->start_busy(2);
        message_vision("$N����ʮ�ָ����������������ȥ����\n", me);
        message_vision("$Nֻ���ӿ���ϵ���������ʯͷ��$N��ͷȥѰ�ҡ�\n",me);
if (random(12)> 1)
{
        message_vision("$Nֻ����ʯ������������������$N��ôҲ�Ҳ�����\n",me);
        me->receive_damage("qi", 10);
        me->receive_damage("jing", 10);
        me->start_busy(16);
        return 1;        
}        	

        // ֱ�Ӽӳ����������ϵͳ����
        i = me->query("kar") + me->query("str") + me->query("int");
        
	//1 �Ƿ���Եõ�xuantie
	if ((sk>250) && (random(sk+i))>( (sk+90)*999/1000) )
	{
		message_vision("$N�ڵ�һ������ʯ!!!\n", me);
                me->receive_damage("qi", 20);
        	me->receive_damage("jing", 20);

                ob = new(__DIR__"kuangshi/xuantie_stone");      
                ob->move(me);
                return 1;
        }
        
        //2 �Ƿ���Եõ�wujin
        if ((sk>200) && (random(sk+i))>((sk+85)*999/1000))
	{
		message_vision("$N�ڵ�һ���ڽ�ʯ!!!\n", me);
                me->receive_damage("qi", 20);
	        me->receive_damage("jing", 20);
                
                ob = new(__DIR__"kuangshi/wujin_stone");      
                ob->move(me);
                return 1;
        }
        
        //3 �Ƿ���Եõ�baijin
        if ((sk>160) && (random(sk+i))>((sk+80)*999/1000))
	{
		message_vision("$N�ڵ�һ�Ű׽�ʯ!!!\n", me);
                me->receive_damage("qi", 15);
        	me->receive_damage("jing", 15);
                
                ob = new(__DIR__"kuangshi/baijin_stone");      
                ob->move(me);
                return 1;
        }
        
        //4
        if ((sk>100) && (random(sk+i))>((sk+75)*999/1000))
	{
		message_vision("$N�ڵ�һ�ź��ʯ!!!\n", me);
                me->receive_damage("qi", 10);
	        me->receive_damage("jing", 10);
                
                ob = new(__DIR__"kuangshi/hongkuang_stone");      
                ob->move(me);
                return 1;
        }
        
        //5
        if ((sk>50) && (random(sk+i))>((sk+70)*995/1000))
	{
		message_vision("$N�ڵ�һ���Ͽ�ʯ!!!\n", me);
                me->receive_damage("qi", 10);
        	me->receive_damage("jing", 10);
                
                ob = new(__DIR__"kuangshi/zikuang_stone");      
                ob->move(me);
                return 1;
        }
        
        //6
        if ((sk>20) && (random(sk+i))>((sk+65)*990/1000))
	{
		message_vision("$N�ڵ�һ���̿�ʯ!!!\n", me);
                me->receive_damage("qi", 10);
        	me->receive_damage("jing", 10);
                
                ob = new(__DIR__"kuangshi/lvkuang_stone");      
                ob->move(me);
                return 1;
        }
        
        //7
        if ((random(sk+i))>((sk+70)*9/10))
	{
		message_vision("$N�ڵ�һ����ͭʯ!!!\n", me);
                me->receive_damage("qi", 10);
	        me->receive_damage("jing", 10);
                
                ob = new(__DIR__"kuangshi/qingtong_stone");      
                ob->move(me);
                return 1;
        }
        
        message_vision("$Nֻ����ʯ������������������$N��ôҲ�Ҳ�����\n",me);
        me->receive_damage("qi", 10);
        me->receive_damage("jing", 10);
        me->start_busy(16);
        return 1;        
}