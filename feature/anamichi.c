#include <ansi.h>

int get_anamichi(object me,string meridian,mapping *anamichis);
mapping get_meridian(string meri);
mapping *get_anamichis(string meri);
int chongxue(object me, string meridian);
int breaking(object me);

/*Ч���ֱ�Ϊ��A���Ӿ�����B������Ѫ��Cս���лָ�������D�ָ���Ѫ*/
//��Ѩ����ţ�5����һ����Ч��10���¶�����Ч������10��������Ч��ȫͨ����������������Ч����Ч��

mapping *meridians = ({
(["mer":"�� �� ��","A":2,"B":2,"C":2,"D":2,]),
(["mer":"�� ά ��","A":2,"B":2,"C":2,"D":2,]),
(["mer":"�� �� ��","A":2,"B":2,"C":2,"D":2,]),
(["mer":"��    ��","A":2,"B":2,"C":2,"D":2,]),
(["mer":"�� ά ��","A":2,"B":2,"C":2,"D":2,]),
(["mer":"��    ��","A":2,"B":2,"C":2,"D":2,]),
(["mer":"��    ��","A":2,"B":2,"C":2,"D":2,]),
(["mer":"��    ��","A":2,"B":2,"C":2,"D":2,]),
(["mer":"��������","A":2,"B":2,"C":2,"D":2,]),
	});

mapping *anamichi_m1 = ({
(["ana":"Ȼ��Ѩ","A":1,"B":0,"C":0,"D":0,"force":100]),
(["ana":"�պ�Ѩ","A":1,"B":0,"C":0,"D":0,"force":125]),
(["ana":"����Ѩ","A":0,"B":1,"C":0,"D":0,"force":150]),
(["ana":"����Ѩ","A":0,"B":1,"C":0,"D":0,"force":175]),
(["ana":"���Ѩ","A":1,"B":0,"C":0,"D":0,"force":200]),
(["ana":"����Ѩ","A":0,"B":0,"C":1,"D":0,"force":225]),
(["ana":"���Ѩ","A":1,"B":0,"C":1,"D":0,"force":250]),
(["ana":"��ȱѨ","A":1,"B":0,"C":0,"D":1,"force":275]),
(["ana":"��ӭѨ","A":1,"B":0,"C":0,"D":1,"force":300]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":0,"force":325]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":0,"force":350]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":1,"force":375]),
(["ana":"���Ѩ","A":0,"B":1,"C":1,"D":1,"force":400]),
(["ana":"������","A":1,"B":0,"C":1,"D":1,"force":425]),
(["ana":"��¡Ѩ","A":0,"B":1,"C":1,"D":1,"force":450]),
(["ana":"��ϪѨ","A":1,"B":1,"C":1,"D":0,"force":475]),
(["ana":"����Ѩ","A":1,"B":1,"C":1,"D":0,"force":500]),
(["ana":"����Ѩ","A":1,"B":1,"C":1,"D":0,"force":525]),
	});
mapping *anamichi_m2 = ({
(["ana":"����Ѩ","A":0,"B":0,"C":0,"D":1,"force":100]),
(["ana":"���Ѩ","A":0,"B":1,"C":0,"D":0,"force":125]),
(["ana":"����Ѩ","A":1,"B":0,"C":0,"D":0,"force":150]),
(["ana":"����Ѩ","A":0,"B":0,"C":1,"D":0,"force":175]),
(["ana":"����Ѩ","A":1,"B":0,"C":0,"D":0,"force":200]),
(["ana":"��ȪѨ","A":0,"B":0,"C":0,"D":1,"force":225]),
(["ana":"��ȪѨ","A":0,"B":1,"C":0,"D":1,"force":250]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":0,"force":275]),
(["ana":"�ٺ�Ѩ","A":1,"B":0,"C":0,"D":1,"force":300]),
(["ana":"���Ѩ","A":1,"B":0,"C":0,"D":1,"force":325]),
(["ana":"ͨ��Ѩ","A":0,"B":1,"C":1,"D":0,"force":350]),
(["ana":"��ۧѨ","A":1,"B":0,"C":1,"D":1,"force":375]),
(["ana":"����Ѩ","A":1,"B":1,"C":1,"D":0,"force":400]),
(["ana":"�ٸ�Ѩ","A":1,"B":0,"C":1,"D":1,"force":425]),
(["ana":"�ٳ�Ѩ","A":0,"B":1,"C":1,"D":1,"force":450]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":475]),
	});
mapping *anamichi_m3 = ({
(["ana":"����Ѩ","A":0,"B":0,"C":1,"D":0,"force":100]),
(["ana":"�Ͳ�Ѩ","A":0,"B":0,"C":0,"D":1,"force":125]),
(["ana":"����Ѩ","A":0,"B":0,"C":0,"D":1,"force":150]),
(["ana":"���sѨ","A":0,"B":0,"C":0,"D":1,"force":175]),
(["ana":"Ğ��Ѩ","A":1,"B":0,"C":0,"D":0,"force":200]),
(["ana":"���kѨ","A":0,"B":0,"C":1,"D":0,"force":225]),
(["ana":"�޹�Ѩ","A":1,"B":0,"C":1,"D":0,"force":250]),
(["ana":"�ز�Ѩ","A":0,"B":0,"C":1,"D":1,"force":275]),
(["ana":"���sѨ","A":0,"B":0,"C":1,"D":1,"force":300]),
(["ana":"����Ѩ","A":0,"B":0,"C":1,"D":1,"force":325]),
(["ana":"���Ѩ","A":1,"B":1,"C":0,"D":0,"force":350]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":1,"force":375]),
(["ana":"ü��Ѩ","A":1,"B":1,"C":1,"D":0,"force":400]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":1,"force":425]),
(["ana":"�崦Ѩ","A":1,"B":1,"C":1,"D":0,"force":450]),
(["ana":"�й�Ѩ","A":0,"B":1,"C":1,"D":1,"force":475]),
(["ana":"ͨ��Ѩ","A":1,"B":0,"C":1,"D":1,"force":500]),
(["ana":"��ȴѨ","A":1,"B":1,"C":0,"D":1,"force":525]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":550]),
(["ana":"����Ѩ","A":1,"B":1,"C":1,"D":0,"force":575]),
(["ana":"��ɽѨ","A":1,"B":0,"C":1,"D":1,"force":600]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":625]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":650]),
	});
mapping *anamichi_m4 = ({
(["ana":"����Ѩ","A":0,"B":0,"C":1,"D":0,"force":100]),
(["ana":"����Ѩ","A":1,"B":0,"C":0,"D":0,"force":125]),
(["ana":"ά  Ѩ","A":0,"B":0,"C":0,"D":1,"force":150]),
(["ana":"���Ѩ","A":0,"B":0,"C":0,"D":1,"force":175]),
(["ana":"����Ѩ","A":0,"B":1,"C":0,"D":0,"force":200]),
(["ana":"ͷ����","A":0,"B":1,"C":0,"D":0,"force":225]),
(["ana":"���Ѩ","A":1,"B":0,"C":1,"D":0,"force":250]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":0,"force":275]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":0,"force":300]),
(["ana":"ͷ����","A":0,"B":0,"C":1,"D":1,"force":325]),
(["ana":"Ŀ��Ѩ","A":0,"B":0,"C":1,"D":1,"force":350]),
(["ana":"��ӪѨ","A":1,"B":1,"C":1,"D":0,"force":375]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":1,"force":400]),
(["ana":"�Կ�Ѩ","A":0,"B":1,"C":1,"D":1,"force":425]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":450]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":475]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":1,"force":500]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":525]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":550]),
	});
mapping *anamichi_m5 = ({
(["ana":"����Ѩ","A":0,"B":1,"C":0,"D":0,"force":100]),
(["ana":"����Ѩ","A":0,"B":0,"C":0,"D":1,"force":125]),
(["ana":"Ğ��Ѩ","A":0,"B":1,"C":0,"D":0,"force":150]),
(["ana":"���sѨ","A":0,"B":1,"C":0,"D":0,"force":175]),
(["ana":"�羮Ѩ","A":0,"B":0,"C":1,"D":0,"force":200]),
(["ana":"ͷάѨ","A":0,"B":1,"C":0,"D":0,"force":225]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":0,"force":250]),
(["ana":"����Ѩ","A":0,"B":0,"C":1,"D":1,"force":275]),
(["ana":"ͷ����","A":0,"B":1,"C":1,"D":0,"force":300]),
(["ana":"Ŀ��Ѩ","A":1,"B":1,"C":0,"D":0,"force":325]),
(["ana":"��ӪѨ","A":1,"B":1,"C":0,"D":0,"force":350]),
(["ana":"����Ѩ","A":1,"B":1,"C":1,"D":0,"force":375]),
(["ana":"�Կ�Ѩ","A":1,"B":1,"C":0,"D":1,"force":400]),
(["ana":"���Ѩ","A":1,"B":1,"C":0,"D":1,"force":425]),
(["ana":"�縮Ѩ","A":1,"B":1,"C":0,"D":1,"force":450]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":1,"force":475]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":500]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":1,"force":525]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":1,"force":550]),
(["ana":"��ȱѨ","A":1,"B":0,"C":1,"D":1,"force":575]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":1,"force":600]),
(["ana":"̫ԨѨ","A":0,"B":1,"C":1,"D":1,"force":625]),
(["ana":"���Ѩ","A":0,"B":1,"C":1,"D":1,"force":650]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":1,"force":675]),
	});
mapping *anamichi_m6 = ({
(["ana":"����Ѩ","A":1,"B":0,"C":0,"D":0,"force":100]),
(["ana":"����Ѩ","A":1,"B":0,"C":0,"D":0,"force":125]),
(["ana":"����Ѩ","A":0,"B":0,"C":0,"D":1,"force":150]),
(["ana":"���Ѩ","A":0,"B":1,"C":0,"D":0,"force":175]),
(["ana":"���Ѩ","A":1,"B":0,"C":0,"D":0,"force":200]),
(["ana":"��  Ѩ","A":0,"B":0,"C":1,"D":0,"force":225]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":0,"force":250]),
(["ana":"��עѨ","A":0,"B":1,"C":0,"D":1,"force":275]),
(["ana":"����Ѩ","A":1,"B":0,"C":0,"D":1,"force":300]),
(["ana":"����Ѩ","A":1,"B":0,"C":0,"D":1,"force":325]),
(["ana":"ʯ��Ѩ","A":1,"B":0,"C":1,"D":0,"force":350]),
(["ana":"����Ѩ","A":1,"B":1,"C":1,"D":0,"force":375]),
(["ana":"ͨ��Ѩ","A":1,"B":1,"C":0,"D":1,"force":400]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":425]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":1,"force":450]),
(["ana":"̫��Ѩ","A":1,"B":0,"C":1,"D":1,"force":475]),
(["ana":"������","A":1,"B":0,"C":1,"D":1,"force":500]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":1,"force":525]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":550]),
(["ana":"���Ѩ","A":0,"B":1,"C":1,"D":1,"force":575]),
(["ana":"ˮ��Ѩ","A":1,"B":0,"C":1,"D":1,"force":600]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":1,"force":625]),
(["ana":"ˮͻѨ","A":1,"B":1,"C":0,"D":1,"force":650]),
(["ana":"����Ѩ","A":1,"B":1,"C":1,"D":0,"force":675]),
	});
mapping *anamichi_m7 = ({
(["ana":"��ǿѨ","A":0,"B":0,"C":1,"D":0,"force":100]),
(["ana":"����Ѩ","A":0,"B":0,"C":1,"D":0,"force":125]),
(["ana":"����Ѩ","A":0,"B":0,"C":0,"D":1,"force":150]),
(["ana":"����Ѩ","A":0,"B":1,"C":0,"D":0,"force":175]),
(["ana":"����Ѩ","A":0,"B":1,"C":0,"D":0,"force":200]),
(["ana":"������","A":0,"B":0,"C":1,"D":0,"force":225]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":0,"force":250]),
(["ana":"��̨Ѩ","A":1,"B":1,"C":0,"D":0,"force":275]),
(["ana":"���Ѩ","A":0,"B":1,"C":0,"D":1,"force":300]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":0,"force":325]),
(["ana":"�յ���","A":1,"B":0,"C":1,"D":0,"force":350]),
(["ana":"��׵Ѩ","A":1,"B":0,"C":1,"D":1,"force":375]),
(["ana":"�縮Ѩ","A":1,"B":1,"C":0,"D":1,"force":400]),
(["ana":"�Ի�Ѩ","A":1,"B":1,"C":1,"D":0,"force":425]),
(["ana":"ǿ��Ѩ","A":1,"B":0,"C":1,"D":1,"force":450]),
(["ana":"����","A":0,"B":1,"C":1,"D":1,"force":475]),
(["ana":"�ٻ�Ѩ","A":0,"B":1,"C":1,"D":1,"force":500]),
(["ana":"ض��Ѩ","A":0,"B":1,"C":1,"D":1,"force":525]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":1,"force":550]),
(["ana":"��ͥѨ","A":1,"B":1,"C":1,"D":0,"force":575]),
(["ana":"��  Ѩ","A":0,"B":1,"C":1,"D":1,"force":600]),
(["ana":"ˮ��Ѩ","A":1,"B":1,"C":1,"D":0,"force":625]),
(["ana":"�Ҷ�Ѩ","A":1,"B":0,"C":1,"D":1,"force":650]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":1,"force":675]),
	});
mapping *anamichi_m8 = ({
(["ana":"����Ѩ","A":1,"B":0,"C":0,"D":0,"force":100]),
(["ana":"�м�Ѩ","A":0,"B":0,"C":1,"D":0,"force":125]),
(["ana":"��ԪѨ","A":0,"B":0,"C":1,"D":0,"force":150]),
(["ana":"����Ѩ","A":0,"B":0,"C":1,"D":0,"force":175]),
(["ana":"����Ѩ","A":0,"B":0,"C":0,"D":1,"force":200]),
(["ana":"����Ѩ","A":0,"B":0,"C":1,"D":0,"force":225]),
(["ana":"��ͻѨ","A":0,"B":1,"C":0,"D":1,"force":250]),
(["ana":"��ȪѨ","A":1,"B":0,"C":0,"D":1,"force":275]),
(["ana":"�н�Ѩ","A":1,"B":0,"C":1,"D":0,"force":300]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":0,"force":325]),
(["ana":"ˮȪѨ","A":1,"B":0,"C":0,"D":1,"force":350]),
(["ana":"���Ѩ","A":1,"B":1,"C":1,"D":0,"force":375]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":400]),
(["ana":"����Ѩ","A":1,"B":1,"C":1,"D":0,"force":425]),
(["ana":"ӿȪѨ","A":1,"B":1,"C":0,"D":1,"force":450]),
(["ana":"���Ѩ","A":1,"B":1,"C":1,"D":0,"force":475]),
(["ana":"�ػ�Ѩ","A":1,"B":0,"C":1,"D":1,"force":500]),
(["ana":"Ѫ��Ѩ","A":1,"B":1,"C":1,"D":0,"force":525]),
(["ana":"��ͨ��","A":1,"B":1,"C":1,"D":0,"force":550]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":575]),
(["ana":"���Ѩ","A":0,"B":1,"C":1,"D":1,"force":600]),
(["ana":"�ḮѨ","A":1,"B":1,"C":0,"D":1,"force":625]),
(["ana":"����Ѩ","A":1,"B":1,"C":1,"D":0,"force":650]),
(["ana":"����Ȫ","A":1,"B":0,"C":1,"D":1,"force":675]),
	});
mapping *anamichi_m9 = ({
(["ana":"���Ѩ","A":0,"B":0,"C":0,"D":1,"force":100]),
(["ana":"ӡ��Ѩ","A":0,"B":0,"C":1,"D":0,"force":125]),
(["ana":"����Ѩ","A":0,"B":0,"C":1,"D":0,"force":150]),
(["ana":"̫��Ѩ","A":0,"B":0,"C":0,"D":1,"force":175]),
(["ana":"����Ѩ","A":0,"B":0,"C":1,"D":0,"force":200]),
(["ana":"���Ѩ","A":0,"B":1,"C":0,"D":0,"force":225]),
(["ana":"���Ѩ","A":1,"B":0,"C":1,"D":0,"force":250]),
(["ana":"��ҺѨ","A":1,"B":0,"C":1,"D":0,"force":275]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":0,"force":300]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":0,"force":325]),
(["ana":"�м�Ѩ","A":1,"B":1,"C":0,"D":0,"force":350]),
(["ana":"����Ѩ","A":1,"B":1,"C":0,"D":1,"force":375]),
(["ana":"����Ѩ","A":1,"B":0,"C":1,"D":1,"force":400]),
(["ana":"��ʹ��","A":1,"B":0,"C":1,"D":1,"force":425]),
(["ana":"��аѨ","A":0,"B":1,"C":1,"D":1,"force":450]),
(["ana":"�ķ�Ѩ","A":1,"B":0,"C":1,"D":1,"force":475]),
(["ana":"ʮ��Ѩ","A":0,"B":1,"C":1,"D":1,"force":500]),
(["ana":"�׶�Ѩ","A":1,"B":1,"C":1,"D":0,"force":525]),
(["ana":"�ٳ���","A":1,"B":0,"C":1,"D":1,"force":550]),
(["ana":"ϥ��Ѩ","A":0,"B":1,"C":1,"D":1,"force":575]),
(["ana":"����Ѩ","A":0,"B":1,"C":1,"D":1,"force":600]),
(["ana":"��βѨ","A":0,"B":1,"C":1,"D":1,"force":625]),
(["ana":"�˷�Ѩ","A":1,"B":0,"C":1,"D":1,"force":650]),
	});
int chongxue(object me, string arg)
{
	object where;
	int i;
	string meri;
	mapping anamichi;
	mapping *anamichis;
	mapping meridian;
	seteuid(getuid());
	where = environment(me);
	
	switch (arg)
	{
		case "m1":
		case "m2":
		case "m3":
		case "m4":
		case "m5":
		case "m6":
		case "m7":
		case "m8":
		case "m9":
			break;
		default:
			return notify_fail("��ָ����������! (m1-m9)\n");
	}

	meri = arg;
	meridian = get_meridian(meri);
	anamichis = get_anamichis(meri);
		
	//�������徭����Ѩ�������������ֻ�ܰ�Ѩλ˳�����γ�Ѩ
	i = get_anamichi(me,arg,anamichis);
	if(i>=(sizeof(anamichis)))
		return notify_fail(meridian["mer"]+"��Ѩ�����Ѿ�ȫ����ͨ��û�б�Ҫ�ٴ�ͨһ��!\n");
	
	//if (i<=0) i=0;
	anamichi=anamichis[i];

	if (where->query("pigging"))
	    return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
	
	if (! where->query("no_fight"))
	    return notify_fail("�������ͨ����Ѩ������̫��ȫ�ɣ�\n");
	
	if (! where->query("sleep_room"))
	    return notify_fail("�����һ���ܹ���Ϣ�ĵط��չ����С�\n");
	
	if ( where->query("pingan"))
	    return notify_fail("����ط�������\n");
	
	if ( where->query("biwu"))
	    return notify_fail("����ط�������\n");
	
	if ( where->query("citybiwu"))
	    return notify_fail("����ط�������\n");


//	if (!wizardp(me))
//	    return notify_fail("δ����,�ڲ������С�\n");

	
	if (me->query_temp("biguan"))
	    return notify_fail("�����ڱչش�ͨ������\n");
	
	if (me->is_busy())
	    return notify_fail("��������æ���ء�\n");
		
	if ((int)me->query("qi") * 100 / me->query("max_qi") < 90)
	    return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");
	
	if ((int)me->query("jing") * 100 / me->query("max_jing") < 90)
	    return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");
	
	if ((int)me->query("max_neili") < (int)anamichi["force"]*3/2)
	    return notify_fail("������������в��㣬����Ŀǰ�����Դ�ͨ"+meridian["mer"]+"��"+anamichi["ana"]+"��\n");

	if ((int)me->query_skill("force", 1) < (int)anamichi["force"])
	    return notify_fail("������Լ����ڹ�������ޣ�������Ҫ�ȶ������ڹ����С�\n");

	if ((int)me->query("neili") * 100 / me->query("max_neili") < 90)
	    return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");
	if (me->query_condition("bg_busy") && !wizardp(me))
	    return notify_fail("��ձչ��أ���Ϣ����������!\n");
	
	message_vision("$N��ϥ���£���ʼڤ���˹����չ����У���ͼ��ͨ"+meridian["mer"]+"��"+HIY+anamichi["ana"]+NOR"��\n", me);
		
	me->set_temp("biguan", 1);
	me->set("doing", "breakup");
	me->set_temp("meri",meri);
	me->set_temp("anami",i);
	//message_vision("$N����"+meri+"��"+i+NOR"��\n", me);
	
	me->apply_condition("bg_busy",100);
	me->start_busy(10);

        //if (call_out("breaking", 10, me) && !me->query("breakup"))
                call_out("breaking", 10, me);
	return 1;
}

int breaking(object me)
{
	string msg;
	int i,anaok,merok,tempana;
	string meri = me->query_temp("meri");
	int anami= (int)me->query_temp("anami");
  int nl,fc;	
	mapping meridian = get_meridian(meri);
	mapping *anamichis = get_anamichis(meri);
	mapping anamichi = anamichis[anami];
	//message_vision("����!", me);


	if (!me)  return notify_fail("���Ѿ������ˣ�\n");
    anaok = 0;
    merok = 0;


	if( !me->query_temp("biguan") )
        {
                tell_object(me, "������´��ٳ�Ѩ��\n");
                message_vision("$N����˫Ŀ����������һ������վ��������\n", me);

                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        me->set_temp("biguan", 0);
                        		me->delete_temp("meri");
		me->delete_temp("anami");
                        call_out("user_quit", 0, me);
                }

                return 0;
        }



        if( (int)me->query("potential") < 10 )
        {
                tell_object(me, "���Ǳ�ܺľ��ˡ�\n");
                message_vision("$N����˫Ŀ����������һ������վ��������\n", me);

                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        me->set_temp("biguan", 0);
		me->delete_temp("meri");
		me->delete_temp("anami");
                        call_out("user_quit", 0, me);
                }

                return 0;
        }


if((int)me->query("potential") - (int)me->query("learned_points") < 200 ) 
        {
                tell_object(me, "���Ǳ�ܺľ��ˡ�\n");
                message_vision("$N����˫Ŀ����������һ������վ��������\n", me);

                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        me->set_temp("biguan", 0);
		me->delete_temp("meri");
		me->delete_temp("anami");
                        call_out("user_quit", 0, me);
                }

                return 0;
        }
	if( (int)me->query("learned_points") < 1 )
        {
                tell_object(me, "���Ǳ�ܺľ��ˡ�\n");
                message_vision("$N����˫Ŀ����������һ������վ��������\n", me);

                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        me->set_temp("biguan", 0);
                        		me->delete_temp("meri");
		me->delete_temp("anami");
                        call_out("user_quit", 0, me);
                }

                return 0;
        }
        if (me->query("potential") <= me->query("learned_points"))
        {
                tell_object(me, "���Ǳ�ܺľ��ˡ�\n");
                message_vision("$N����˫Ŀ����������һ������վ��������\n", me);

                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        		me->delete_temp("meri");
		me->delete_temp("anami");
                        me->set_temp("biguan", 0);
                        call_out("user_quit", 0, me);
                }

                return 0;
        }

        if (random(2)==0) me->add("potential",-1);


	if (random(me->query_skill("force",1)*6) < me->query("con") *me->query_skill("force",1) /100 && (me->query("ana/"+meri)< (anami+1)))
	{
		message_vision(HIW "ֻ��$N" HIW "ͷ�ϰ������ڡ�����"
					 "��ͬ���������У������Ѿ����������۶���"
					 "������Ԫ��������á����˽���Ľ�Ҫ��ͷ��\n" NOR, me);
		tell_object(me, HIR "����������ڵ���ԴԴ����������"
				  "���"+meridian["mer"]+"��"+anamichi["ana"]+HIR"�����������ѵ�����������������\n" NOR);
		message_vision(HIC "ͻȻ$N" HIC "���һ����һ����������"
					 "��Ȼɢ�����������ܿ�����ʱ������ȡ�\n" NOR, me);
		tell_object(me, HIG "���ʱ���û���һ�����ɣ�һ������֮����Ȼ"
				  "��������һƬ����������ͨ��"+meridian["mer"]+"��"+anamichi["ana"]+HIG"ʱû��˿�����ͣ���̩֮����\n" NOR);
		tell_object(me, HIC "��ϲ���ͨ��"+meridian["mer"]+"��"+anamichi["ana"]+HIC+"������Ϊ������һ��̨�ס�\n" NOR);
		if (anami+1>=sizeof(anamichis))
		{
			anaok = 1;
			tell_object(me, HIG "��ϲ���ͨ��"+meridian["mer"] + "������Ѩ����������"+meridian["mer"] + "������Ѩ�����ߣ���ͨ�ޱȡ�\n" NOR);
		}	
		me->set_temp("biguan", 0);
		me->delete_temp("meri");
		me->delete_temp("anami");
		anami=anami+1;
		me->set("ana/"+meri, anami);

if (!present("chongxue tongren", me))
{

nl=me->query("max_neili",1)-me->query("max_neili",1)/4;	
fc=me->query_skill("force",1)-me->query_skill("force",1)/4;
        if (random(80)==2  && !present("chongxue tongren", me))
{
me->set_skill("force",fc);
me->set("max_neili",nl);
me->die();
			tell_object(me, HIR "�������Ѫ����Ѫ��ֹ�������߻���ħ��ҩ�ɾ��ˡ�\n" NOR);	
}	
else        if (random(60)==0 && !present("chongxue tongren", me))
{
me->set("max_neili",nl);
			tell_object(me, RED "���³�һ����Ѫ�������߻���ħ�ˣ��ڹ��ܵ������ˡ�\n" NOR);	
}	
else        if (random(70)==1 && !present("chongxue tongren", me))
{
me->set_skill("force",fc);
			tell_object(me, RED "���³�һ�����Ѫ�������߻���ħ�ˣ������ܵ������ˡ�\n" NOR);	
}	


}




			//����ȫͨ��
			if ((get_anamichi(me,"m1",anamichi_m1)>=sizeof(anamichi_m1)) &&
				(get_anamichi(me,"m2",anamichi_m2)>=sizeof(anamichi_m2)) &&
				(get_anamichi(me,"m3",anamichi_m3)>=sizeof(anamichi_m3)) &&
				(get_anamichi(me,"m4",anamichi_m4)>=sizeof(anamichi_m4)) &&
				(get_anamichi(me,"m5",anamichi_m5)>=sizeof(anamichi_m5)) &&
				(get_anamichi(me,"m6",anamichi_m6)>=sizeof(anamichi_m6)) &&
				(get_anamichi(me,"m7",anamichi_m7)>=sizeof(anamichi_m7)) &&
				(get_anamichi(me,"m8",anamichi_m8)>=sizeof(anamichi_m8)) &&
				(get_anamichi(me,"m9",anamichi_m9)>=sizeof(anamichi_m9)))
			{
				merok = 1;
				tell_object(me, HIC "��ϲ���ͨ�����о�����������ȫ�������Ѩ�����ߣ���ͨ�ޱȡ�\n" NOR);
			}

		//����������������ӣ������ӵ���ֵ��force��1/50
		me->add("max_jing",me->query_skill("force",1)*2 /50*(int)anamichi["A"]);
		me->add("eff_jing",me->query_skill("force",1)*2 /50*(int)anamichi["A"]);

		me->add("max_qi",me->query_skill("force",1)*2 /50*(int)anamichi["B"]);
		me->add("eff_qi",me->query_skill("force",1)*2 /50*(int)anamichi["B"]);
		
		me->add("combat_exp",(int)anamichi["force"]*100);
		me->add("potential",(int)anamichi["force"]*50);
		//�þ���ȫͨ
		if (anaok==1)
		{
			//����������������ӣ������ӵ���ֵ��force��1/50
			me->add("max_jing",me->query_skill("force",1)*2 /50*(int)meridian["A"]);
			me->add("eff_jing",me->query_skill("force",1)*2 /50*(int)meridian["A"]);
		
			me->add("max_qi",me->query_skill("force",1)*2 /50*(int)meridian["B"]);
			me->add("eff_qi",me->query_skill("force",1)*2 /50*(int)meridian["B"]);
			
			me->add("combat_exp",me->query_skill("force",1) *100);
			me->add("potential",me->query_skill("force",1) *50);
		}	

		//���о���ȫͨ
		if (merok==1)
		{
			//����������������ӣ������ӵ���ֵ��force��1/10
			me->add("max_jing",me->query_skill("force",1)*2 /10);
			me->add("eff_jing",me->query_skill("force",1)*2 /10);
		
			me->add("max_qi",me->query_skill("force",1)*2 /10);
			me->add("eff_qi",me->query_skill("force",1)*2 /10);

			me->add("combat_exp",me->query_skill("force",1) *300);
			me->add("potential",me->query_skill("force",1) *200);
          me->set("breakup", 1);
   	    me->set_skill("biguan",200);
			
		}	

		me->save();
		return 0;
	}
	else
	{
		switch (random(5))
		{
			case 0:
				msg = "��ĬĬ��ת������������Щ�о���\n";
				me->start_busy(5);
				break;
			case 1:
				msg = "�㽫�����˾���Ѩ������֫���࣬Ȼ���ֻ��յ��\n";
				me->start_busy(5);
				break;
			case 2:
				msg = "���ڵ����в��ϻ���������ֻ���û������ȡ�\n";
				me->start_busy(5);
				break;
			default:
				msg = "�㻺���������ɣ���������ˮ¶����Ϊ���á�\n";
				me->start_busy(5);
				break;
		}
	
		tell_object(me, msg);
		call_out("breaking", 5, me);
		return 0;
	}
}

int get_anamichi(object me,string meridian,mapping *anamichis)
{
	if ((int)me->query("ana/"+meridian)>=sizeof(anamichis))
		return sizeof(anamichis);
	else
		return (int)me->query("ana/"+meridian);
}

mapping get_meridian(string meri)
{
	mapping meridian;
	switch (meri)
	{
		case "m1":
			meridian = meridians[0];
			break;
		case "m2":
			meridian = meridians[1];
			break;
		case "m3":
			meridian = meridians[2];
			break;
		case "m4":
			meridian = meridians[3];
			break;
		case "m5":
			meridian = meridians[4];
			break;
		case "m6":
			meridian = meridians[5];
			break;
		case "m7":
			meridian = meridians[6];
			break;
		case "m8":
			meridian = meridians[7];
			break;
		case "m9":
			meridian = meridians[8];
			break;
	}
	return meridian;
}

mapping *get_anamichis(string meri)
{
	mapping *anamichis;
	switch (meri)
	{
		case "m1":
			anamichis = anamichi_m1;
			break;
		case "m2":
			anamichis = anamichi_m2;
			break;
		case "m3":
			anamichis = anamichi_m3;
			break;
		case "m4":
			anamichis = anamichi_m4;
			break;
		case "m5":
			anamichis = anamichi_m5;
			break;
		case "m6":
			anamichis = anamichi_m6;
			break;
		case "m7":
			anamichis = anamichi_m7;
			break;
		case "m8":
			anamichis = anamichi_m8;
			break;
		case "m9":
			anamichis = anamichi_m9;
			break;
	}
	return anamichis;
}
