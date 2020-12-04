#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
#include "/quest/menpai/romnpc5.c"


mapping *data=({
(["name":"��������ͽ",	"id":"xspt",	"mw":-1,	]),
(["name":"���½���ͽ",	"id":"rypt",	"mw":1,	]),
(["name":"���ߵ���ͽ	",	"id":"lspt",	"mw":-1,]),
(["name":"ؤ����ͽ",	"id":"gbpt",	"mw":1,		]),
(["name":"���»�ɱ��",	"id":"txss",	"mw":1,	]),
(["name":"��ɽ������",	"id":"ssyz",	"mw":-1,	]),
(["name":"��ǰ������",	"id":"swz",		"mw":1,	]),
(["name":"������ͽ",	"id":"slpt",	"mw":1,	]),
(["name":"���չ���ͽ",	"id":"ljgpt",	"mw":-1,		]),
(["name":"ɽ����",		"id":"sdw",	"mw":-1,	]),
(["name":"������ϴ�",	"id":"hld",		"mw":-1,		]),
(["name":"����ɽ��ͽ",	"id":"wlspt",	"mw":1,	]),
(["name":"�ٸ�����",	"id":"bk",	"mw":-1,	]),
(["name":"�ٷ�",	"id":"bfz",	"mw":-1,	]),
(["name":"������",	"id":"cf",	"mw":-1,	]),
(["name":"���Ա",	"id":"gy",	"mw":-1,	]),
(["name":"��������",	"id":"sr",	"mw":-1,	]),
(["name":"����ϸ��",	"id":"hxz",	"mw":-1,	]),
(["name":"����ϸ��",	"id":"rxz",	"mw":-1,	]),
(["name":"��������",	"id":"hns",	"mw":-1,	]),
(["name":"���ҵ�����",	"id":"sw",	"mw":-1,	]),
(["name":"�����ӳ�",	"id":"swdz",	"mw":-1,	]),
(["name":"�䶴Ů",	"id":"ldn",	"mw":-1,"sex":1,	]),
(["name":"��Ӱ��",	"id":"wyz",	"mw":-1,	]),
(["name":"��Ů",	"id":"wn",	"mw":-1,"sex":1,	]),
(["name":"��ǹͷ��",	"id":"hqtl",	"mw":-1,	]),
(["name":"��ǹ����",	"id":"hqsw",	"mw":-1,	]),
(["name":"�����ܹ�",	"id":"yzzg",	"mw":-1,	]),
(["name":"�ױ�ͷ��",	"id":"qbtl",	"mw":-1,	]),
(["name":"�����ױ�",	"id":"wfqb",	"mw":-1,	]),
(["name":"���˻�Ժ",	"id":"erhy",	"mw":-1,	]),
(["name":"�����ɽ�",	"id":"jgqj",	"mw":-1,	]),
(["name":"��ũ��",	"id":"ynf",	"mw":-1,	]),
(["name":"��ũ��",	"id":"enh",	"mw":-1,	]),
(["name":"���",	"id":"ll",	"mw":-1,	]),
(["name":"���ڱ�",	"id":"sb",	"mw":-1,	]),
(["name":"����",	"id":"sw",	"mw":-1,	]),
(["name":"��ʿ",	"id":"ys",	"mw":-1,	]),
(["name":"��ţɽ�Ѿ�",	"id":"fnspj",	"mw":-1,	]),
(["name":"�췴��ʿ��",	"id":"zfsz",	"mw":-1,	]),
(["name":"����ͽ",	"id":"wmt",	"mw":-1,	]),
(["name":"����Ů",	"id":"emn",	"mw":-1,"sex":1,	]),
(["name":"Ұ������",	"id":"yrls",	"mw":-1,	]),
(["name":"��ŭ�Ŀ๤",	"id":"kg",	"mw":-1,	]),
(["name":"���Ե����",	"id":"yj",	"mw":-1,	]),
(["name":"�ΰ����",	"id":"ybbz",	"mw":-1,	]),
(["name":"������",	"id":"tjw",	"mw":-1,	]),
(["name":"�ּױ�",	"id":"gjb",	"mw":-1,	]),
(["name":"���Ļ��",	"id":"fkhj",	"mw":-1,	]),
(["name":"����",	"id":"ks",	"mw":-1,	]),
(["name":"����",	"id":"jj",	"mw":-1,	]),
(["name":"������",	"id":"smr",	"mw":-1,	]),
(["name":"Ѳ���ʿ",	"id":"xcjs",	"mw":-1,	]),
(["name":"���״̿�",	"id":"pjck",	"mw":-1,	]),
(["name":"��ŭ��ʦ̫",	"id":"nst",	"mw":-1,	]),
(["name":"�����ŵ���",	"id":"cydz",	"mw":-1,	]),
(["name":"������",	"id":"hyr",	"mw":-1,	]),
(["name":"С�ӳ�",	"id":"xdz",	"mw":-1,	]),
(["name":"��ū",	"id":"jn",	"mw":-1,	]),
(["name":"����Уξ",	"id":"ylxw",	"mw":-1,	]),
(["name":"���ֵ���",	"id":"sldz",	"mw":-1,	]),
(["name":"���ʿ��",	"id":"jgsb",	"mw":-1,	]),
(["name":"����ͼ����",	"id":"tftgs",	"mw":-1,	]),
(["name":"���õ�ͷ��",	"id":"tl",	"mw":-1,	]),
(["name":"�����������",	"id":"yfr",	"mw":-1,	]),
(["name":"�ξ������",	"id":"jxg",	"mw":-1,	]),
(["name":"���",	"id":"yj",	"mw":-1,	]),
(["name":"��������",	"id":"gwsw",	"mw":-1,	]),
(["name":"��������",	"id":"lksl",	"mw":-1,	]),
(["name":"���ǲ���ĶĿ�",	"id":"dk",	"mw":-1,	]),
(["name":"һƷ����ʿ",	"id":"ybtws",	"mw":-1,	]),
(["name":"����ϸ��",	"id":"tlxz",	"mw":-1,	]),
(["name":"�̿ͻ���",	"id":"ckhw",	"mw":-1,	]),
(["name":"�Ի���",	"id":"mhs",	"mw":-1,	]),
(["name":"�����ʿ",	"id":"shjs",	"mw":-1,	]),
(["name":"����ɮ",	"id":"fzs",	"mw":-1,	]),
(["name":"�������",	"id":"yljs",	"mw":-1,	]),
(["name":"�˵���",	"id":"ldk",	"mw":-1,	]),
(["name":"��������",	"id":"tjmb",	"mw":-1,	]),
(["name":"�Ѿ�ì��",	"id":"pjms",	"mw":-1,	]),
(["name":"���׵���",	"id":"tsdk",	"mw":-1,	]),
(["name":"�������� ",	"id":"jdgs",	"mw":-1,	]),
(["name":"�����ļҶ�",	"id":"bdjd",	"mw":-1,	]),
(["name":"�����ļ๤",	"id":"bdjg",	"mw":-1,	]),
(["name":"�����Ĵ���",	"id":"bdcf",	"mw":-1,	]),
(["name":"�ɻ��� ",	"id":"chz",	"mw":-1,	]),
(["name":"��ǹ����",	"id":"hqhw",	"mw":-1,	]),
(["name":"��թ�Ķ���",	"id":"qzds",	"mw":-1,	]),
(["name":"��ǹ��Ů ",	"id":"hqsn",	"mw":-1,"sex":1,	]),
(["name":"�ɹŽ���",	"id":"mgjl",	"mw":-1,	]),
(["name":"�������",	"id":"jgjl",	"mw":-1,	]),
(["name":"�ι�����",	"id":"sgjl",	"mw":-1,	]),
(["name":"��������ʿ",	"id":"yss",	"mw":-1,	]),
(["name":"�����ʿ",	"id":"swjs",	"mw":-1,	]),
(["name":"��������",	"id":"sw",	"mw":-1,	]),
(["name":"��Ӱ��ʿ",	"id":"wyys",	"mw":-1,	]),
(["name":"��͢����",	"id":"ctsw",	"mw":-1,	]),
(["name":"�ڷ�կ��Ӣ",	"id":"hfjy",	"mw":-1,	]),
(["name":"��Ĺ����",	"id":"dmmz",	"mw":-1,	]),
(["name":"��������",	"id":"hmls",	"mw":-1,	]),
(["name":"��Ů��˾",	"id":"mnjs",	"mw":-1,"sex":1,	]),
(["name":"��������",	"id":"blls",	"mw":-1,	]),
(["name":"�����ؾ�",	"id":"mlsj",	"mw":-1,	]),
(["name":"����������",	"id":"cgmsz",	"mw":-1,	]),
(["name":"������",	"id":"jydd",	"mw":-1,	]),
(["name":"ɽ������",	"id":"jxtf",	"mw":-1,	]),
(["name":"��������",	"id":"jhlz",	"mw":-1,	]),
(["name":"������ʹ��",	"id":"ttrsz",	"mw":-1,	]),
(["name":"�����˻���",	"id":"ttrhw",	"mw":-1,	]),
(["name":"���������",	"id":"tftqb",	"mw":-1,	]),
(["name":"���ľ�ʿ",	"id":"xxjs",	"mw":-1,	]),
(["name":"������",	"id":"xxmf",	"mw":-1,	]),
(["name":"����",	"id":"mb",	"mw":-1,	]),
(["name":"������",	"id":"jyw",	"mw":-1,	]),
(["name":"���ײ����",	"id":"tlbqb",	"mw":-1,	]),
(["name":"��Į����",	"id":"dmdk",	"mw":-1,	]),
(["name":"��˽���̶�",	"id":"zssd",	"mw":-1,	]),
(["name":"�����ٻ�",	"id":"dcbh",	"mw":-1,	]),
(["name":"����ǧ��",	"id":"dcqh",	"mw":-1,	]),
(["name":"��ˮ�����",	"id":"hsyqb",	"mw":-1,	]),
(["name":"�޾������",	"id":"jjbbz",	"mw":-1,	]),
(["name":"���կǿ��",	"id":"qfzqf",	"mw":-1,	]),
(["name":"���կǿ��",	"id":"qfzqf",	"mw":-1,	]),
(["name":"��������� ",	"id":"hgtqb",	"mw":-1,	]),
(["name":"������̽",	"id":"ddmt",	"mw":-1,	]),
(["name":"����ɮ ",	"id":"jws",	"mw":-1,	]),
(["name":"�ڷ�կ��� ",	"id":"hfzll",	"mw":-1,	]),
(["name":"ѲԺ�ӳ�",	"id":"xydz",	"mw":-1,	]),
(["name":"����",	"id":"qz",	"mw":-1,	]),
(["name":"�����ٱ�",	"id":"xxgb",	"mw":-1,	]),
(["name":"���ν���",	"id":"dsjj",	"mw":-1,	]),
(["name":"ƭ�˵���ף",	"id":"brmz",	"mw":-1,	]),
(["name":"���ǵ�ɱ��",	"id":"lpss",	"mw":-1,	]),
(["name":"���ŵĵ���",	"id":"lfdk",	"mw":-1,	]),
(["name":"���ŵ���Ů",	"id":"lfwn",	"mw":-1,"sex":1,	]),
(["name":"���ǵ���ʿ",	"id":"lpws",	"mw":-1,	]),
(["name":"�󹤹�ͷ",	"id":"kggt",	"mw":-1,	]),
(["name":"��ɽ����",	"id":"tsqz",	"mw":-1,	]),
(["name":"Сë��",	"id":"xmz",	"mw":-1,	]),
(["name":"������ʿ",	"id":"ddws",	"mw":-1,	]),
(["name":"Ū����",	"id":"nsr",	"mw":-1,	]),
(["name":"���˵���",	"id":"yrdk",	"mw":-1,	]),
(["name":"��ˮ����",	"id":"hsdk",	"mw":-1,	]),
(["name":"��ˮ��ʿ",	"id":"hsjs",	"mw":-1,	]),
(["name":"����������",	"id":"tzql",	"mw":-1,	]),
(["name":"����������",	"id":"dzyz",	"mw":-1,	]),
(["name":"�������",	"id":"jgjz",	"mw":-1,	]),
(["name":"Ѩ����Ұ��",	"id":"yr",	"mw":-1,	]),
(["name":"Ѩ��ŮҰ��",	"id":"nyr",	"mw":-1,"sex":1,	]),
(["name":"������ʿ",	"id":"qmws",	"mw":-1,	]),
(["name":"����ʿ",	"id":"wss",	"mw":-1,	]),
(["name":"������",	"id":"hyr",	"mw":-1,	]),
(["name":"С͵",	"id":"xt",	"mw":-1,	]),
(["name":"��ðɮ��",	"id":"jmsr",	"mw":-1,	]),
(["name":"Ǳ��ɮ��",	"id":"qtsl",	"mw":-1,	]),
(["name":"ɽ�ϱ���",	"id":"snbm",	"mw":-1,	]),
(["name":"���½�ʿ",	"id":"wyjs",	"mw":-1,	]),
(["name":"������ͷĿ",	"id":"xxztm",	"mw":-1,	]),
(["name":"������ʿ",	"id":"nyys",	"mw":-1,	]),
(["name":"���ļ�˾",	"id":"nyjs",	"mw":-1,	]),
(["name":"������Ů",	"id":"tzwn",	"mw":-1,"sex":1,	]),
(["name":"�����ļ���",	"id":"bdjm",	"mw":-1,	]),
(["name":"��������",	"id":"yyxk",	"mw":-1,	]),
(["name":"ɱ�˵��Ի�",	"id":"srlh",	"mw":-1,	]),
(["name":"������",	"id":"xxz",	"mw":-1,	]),
(["name":"����ʿ",	"id":"jrjs",	"mw":-1,	]),
(["name":"ɽ������",	"id":"sbdf",	"mw":-1,	]),
(["name":"����ʿ",	"id":"yjs",	"mw":-1,	]),
(["name":"���ȭʦ",	"id":"trqs",	"mw":-1,	]),
(["name":"����ʿ",	"id":"yjs",	"mw":-1,	]),
(["name":"�ξ�����",	"id":"yjdb",	"mw":-1,	]),
(["name":"�ƼҶ�ʹ",	"id":"tjds",	"mw":-1,	]),
(["name":"�Ƽ����� ",	"id":"tjns",	"mw":-1,	]),
(["name":"�������׼�����",	"id":"plmr",	"mw":-1,	]),
(["name":"����ǹ��",	"id":"hlqb",	"mw":-1,	]),
(["name":"��������",	"id":"hlns",	"mw":-1,	]),
(["name":"���Ӫꢱ�",	"id":"rjyzb",	"mw":-1,	]),
(["name":"���Ӫ���� ",	"id":"rjyjr",	"mw":-1,	]),
(["name":"�н�����",	"id":"xjsr",	"mw":-1,	]),
(["name":"��������",	"id":"nmdk",	"mw":-1,	]),
(["name":"������Ů",	"id":"nmwn",	"mw":-1,"sex":1,	]),
(["name":"��������",	"id":"smsr",	"mw":-1,	]),
(["name":"���ڸ���",	"id":"dngs",	"mw":-1,	]),
(["name":"�����ܹ�",	"id":"dnzg",	"mw":-1,	]),
(["name":"ˮ�����",	"id":"sfyf",	"mw":-1,	]),
(["name":"��Ҿ������� ",	"id":"wjfs",	"mw":-1,	]),
(["name":"��Ҿ���ǹ�� ",	"id":"wjqs",	"mw":-1,	]),
(["name":"Ǯ�Ϸ˱�",	"id":"qsfb",	"mw":-1,	]),
(["name":"�ɹŴ��",	"id":"mgdf",	"mw":-1,	]),
(["name":"����ʿ",	"id":"dls",	"mw":-1,	]),
(["name":"��������",	"id":"mysx",	"mw":-1,	]),
(["name":"ǿ��ͷĿ",	"id":"qxtm",	"mw":-1,	]),
(["name":"����",	"id":"mz",	"mw":-1,	]),
(["name":"���ҵ�����",	"id":"plya",	"mw":-1,	]),
(["name":"����ɮ��",	"id":"yysr",	"mw":-1,	]),
(["name":"�̲���ͷ",	"id":"xbbt",	"mw":-1,	]),
(["name":"���µĲ˷�",	"id":"nscf",	"mw":-1,	]),
(["name":"�ٸ�����",	"id":"gfbk",	"mw":-1,	]),
(["name":"�׻��û���",	"id":"bhthw",	"mw":-1,	]),
(["name":"�������",	"id":"cbbz",	"mw":-1,	]),
});




 


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	//weapon=npc["weapon"];

	set_name(order[random(13)] +npc["name"]+NOR,({ "kill er" }));
	set("age",20+random(30));
	set("gender", "����");
	if (npc["sex"]) set("gender", "Ů��");
set("str",25+random(5));
set("dex",25+random(5));
set("con",25+random(5));
set("int",25+random(5));
set("per",25+random(5));
set("kar",25+random(5));
	set("combat_exp",100000+random(100000));
set("taskid", 1);
	set("max_jing",500);
	set("max_qi",500);
	set("max_neili",1000);
	set_skill("sword",30);
	set_skill("blade",30);
	set_skill("unarmed",30);
	set_skill("sword",30);
	set_skill("club",30);
	set_skill("whip",30);
	set_skill("throwing",30);
	set_skill("parry",30);
	set_skill("dodge",30);
	//set("shen_type",npc["mw"]);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	initlvl(30+random(30));
	this_object()->delete("nickname");
	//if( weapon)
	//	carry_object("/clone/weapon/"+weapon)->wield();
	add_money("silver",8+random(8));
}
       


void die()
{
	string msg;
int i,pot,exp,shen;
	object killer;
	exp= random(88)+188;
	pot= exp*2/3+1;
	if( objectp(killer = query_temp("last_damage_from")))
{
	if (userp(killer))
{
if (killer->query("shen",1)>=0) shen=random(50)+10;
if (killer->query("shen",1)<0) shen=-random(60);
                msg =  "������:";
        if (exp > 0) msg += chinese_number(exp) + "�㾭�� ";
        if (pot > 0) msg += chinese_number(pot) + "��Ǳ�� ";
        if (shen > 0) msg += chinese_number(shen) + "������ ";
        if (shen < 0) msg += chinese_number(-shen) + "�㸺�� ";
        killer->add("combat_exp", exp);
        killer->add("potential", pot);
        killer->add("shen", shen);
 tell_object(killer, msg);
}
}
	::die();

return ;
}

void setn(int rw)
{
	mapping npc;
        object ob = this_object();
	npc=data[rw];
		ob->set_name(order[random(13)] +npc["name"]+NOR,({ "kill er" }));
}

void init()
{
        remove_call_out("leave");
        call_out("leave",60);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}