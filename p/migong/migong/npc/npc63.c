#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
#include "/quest/menpai/romnpc4.c"


mapping *data=({
(["name":"��������ͽ",	"id":"xspt",	"mw":-1,	"tname":"bnpcb1",]),
(["name":"���½���ͽ",	"id":"rypt",	"mw":1,	"tname":"bnpcb2",]),
(["name":"���ߵ���ͽ	",	"id":"lspt",	"mw":-1,"tname":"bnpcb3",]),
(["name":"ؤ����ͽ",	"id":"gbpt",	"mw":1,		"tname":"bnpcb4",]),
(["name":"���»�ɱ��",	"id":"txss",	"mw":1,	"tname":"bnpcb5",]),
(["name":"��ɽ������",	"id":"ssyz",	"mw":-1,	"tname":"bnpcb6",]),
(["name":"��ǰ������",	"id":"swz",		"mw":1,	"tname":"bnpcb7",]),
(["name":"������ͽ",	"id":"slpt",	"mw":1,	"tname":"bnpcb8",]),
(["name":"���չ���ͽ",	"id":"ljgpt",	"mw":-1,		"tname":"bnpcb9",]),
(["name":"ɽ����",		"id":"sdw",	"mw":-1,	"tname":"bnpcb10",]),
(["name":"������ϴ�",	"id":"hld",		"mw":-1,		"tname":"bnpcb11",]),
(["name":"����ɽ��ͽ",	"id":"wlspt",	"mw":1,	"tname":"bnpcb12",]),
(["name":"�ٸ�����",	"id":"bk",	"mw":-1,	"tname":"bnpcb13",]),
(["name":"�ٷ�",	"id":"bfz",	"mw":-1,	"tname":"bnpcb14",]),
(["name":"������",	"id":"cf",	"mw":-1,	"tname":"bnpcb15",]),
(["name":"���Ա",	"id":"gy",	"mw":-1,	"tname":"bnpcb16",]),
(["name":"��������",	"id":"sr",	"mw":-1,	"tname":"bnpcb17",]),
(["name":"����ϸ��",	"id":"hxz",	"mw":-1,	"tname":"bnpcb18",]),
(["name":"����ϸ��",	"id":"rxz",	"mw":-1,	"tname":"bnpcb19",]),
(["name":"��������",	"id":"hns",	"mw":-1,	"tname":"bnpcb20",]),
(["name":"���ҵ�����",	"id":"sw",	"mw":-1,	"tname":"bnpcb21",]),
(["name":"�����ӳ�",	"id":"swdz",	"mw":-1,	"tname":"bnpcb22",]),
(["name":"�䶴Ů",	"id":"ldn",	"mw":-1,"sex":1,	"tname":"bnpcb23",]),
(["name":"��Ӱ��",	"id":"wyz",	"mw":-1,	"tname":"bnpcb24",]),
(["name":"��Ů",	"id":"wn",	"mw":-1,"sex":1,	"tname":"bnpcb25",]),
(["name":"��ǹͷ��",	"id":"hqtl",	"mw":-1,	"tname":"bnpcb26",]),
(["name":"��ǹ����",	"id":"hqsw",	"mw":-1,	"tname":"bnpcb27",]),
(["name":"�����ܹ�",	"id":"yzzg",	"mw":-1,	"tname":"bnpcb28",]),
(["name":"�ױ�ͷ��",	"id":"qbtl",	"mw":-1,	"tname":"bnpcb29",]),
(["name":"�����ױ�",	"id":"wfqb",	"mw":-1,	"tname":"bnpcb30",]),
(["name":"���˻�Ժ",	"id":"erhy",	"mw":-1,	"tname":"bnpcb31",]),
(["name":"�����ɽ�",	"id":"jgqj",	"mw":-1,	"tname":"bnpcb32",]),
(["name":"��ũ��",	"id":"ynf",	"mw":-1,	"tname":"bnpcb33",]),
(["name":"��ũ��",	"id":"enh",	"mw":-1,	"tname":"bnpcb34",]),
(["name":"���",	"id":"ll",	"mw":-1,	"tname":"bnpcb35",]),
(["name":"���ڱ�",	"id":"sb",	"mw":-1,	"tname":"bnpcb36",]),
(["name":"����",	"id":"sw",	"mw":-1,	"tname":"bnpcb37",]),
(["name":"��ʿ",	"id":"ys",	"mw":-1,	"tname":"bnpcb38",]),
(["name":"��ţɽ�Ѿ�",	"id":"fnspj",	"mw":-1,	"tname":"bnpcb39",]),
(["name":"�췴��ʿ��",	"id":"zfsz",	"mw":-1,	"tname":"bnpcb40",]),
(["name":"����ͽ",	"id":"wmt",	"mw":-1,	"tname":"bnpcb41",]),
(["name":"����Ů",	"id":"emn",	"mw":-1,"sex":1,	"tname":"bnpcb42",]),
(["name":"Ұ������",	"id":"yrls",	"mw":-1,	"tname":"bnpcb43",]),
(["name":"��ŭ�Ŀ๤",	"id":"kg",	"mw":-1,	"tname":"bnpcb44",]),
(["name":"���Ե����",	"id":"yj",	"mw":-1,	"tname":"bnpcb45",]),
(["name":"�ΰ����",	"id":"ybbz",	"mw":-1,	"tname":"bnpcb46",]),
(["name":"������",	"id":"tjw",	"mw":-1,	"tname":"bnpcb47",]),
(["name":"�ּױ�",	"id":"gjb",	"mw":-1,	"tname":"bnpcb48",]),
(["name":"���Ļ��",	"id":"fkhj",	"mw":-1,	"tname":"bnpcb49",]),
(["name":"����",	"id":"ks",	"mw":-1,	"tname":"bnpcb50",]),
(["name":"����",	"id":"jj",	"mw":-1,	"tname":"bnpcb51",]),
(["name":"������",	"id":"smr",	"mw":-1,	"tname":"bnpcb52",]),
(["name":"Ѳ���ʿ",	"id":"xcjs",	"mw":-1,	"tname":"bnpcb53",]),
(["name":"���״̿�",	"id":"pjck",	"mw":-1,	"tname":"bnpcb54",]),
(["name":"��ŭ��ʦ̫",	"id":"nst",	"mw":-1,	"tname":"bnpcb55",]),
(["name":"�����ŵ���",	"id":"cydz",	"mw":-1,	"tname":"bnpcb56",]),
(["name":"������",	"id":"hyr",	"mw":-1,	"tname":"bnpcb57",]),
(["name":"С�ӳ�",	"id":"xdz",	"mw":-1,	"tname":"bnpcb58",]),
(["name":"��ū",	"id":"jn",	"mw":-1,	"tname":"bnpcb59",]),
(["name":"����Уξ",	"id":"ylxw",	"mw":-1,	"tname":"bnpcb60",]),
(["name":"���ֵ���",	"id":"sldz",	"mw":-1,	"tname":"bnpcb61",]),
(["name":"���ʿ��",	"id":"jgsb",	"mw":-1,	"tname":"bnpcb62",]),
(["name":"����ͼ����",	"id":"tftgs",	"mw":-1,	"tname":"bnpcb63",]),
(["name":"���õ�ͷ��",	"id":"tl",	"mw":-1,	"tname":"bnpcb64",]),
(["name":"�����������",	"id":"yfr",	"mw":-1,	"tname":"bnpcb65",]),
(["name":"�ξ������",	"id":"jxg",	"mw":-1,	"tname":"bnpcb66",]),
(["name":"���",	"id":"yj",	"mw":-1,	"tname":"bnpcb67",]),
(["name":"��������",	"id":"gwsw",	"mw":-1,	"tname":"bnpcb68",]),
(["name":"��������",	"id":"lksl",	"mw":-1,	"tname":"bnpcb69",]),
(["name":"���ǲ���ĶĿ�",	"id":"dk",	"mw":-1,	"tname":"bnpcb70",]),
(["name":"һƷ����ʿ",	"id":"ybtws",	"mw":-1,	"tname":"bnpcb71",]),
(["name":"����ϸ��",	"id":"tlxz",	"mw":-1,	"tname":"bnpcb72",]),
(["name":"�̿ͻ���",	"id":"ckhw",	"mw":-1,	"tname":"bnpcb73",]),
(["name":"�Ի���",	"id":"mhs",	"mw":-1,	"tname":"bnpcb74",]),
(["name":"�����ʿ",	"id":"shjs",	"mw":-1,	"tname":"bnpcb75",]),
(["name":"����ɮ",	"id":"fzs",	"mw":-1,	"tname":"bnpcb76",]),
(["name":"�������",	"id":"yljs",	"mw":-1,	"tname":"bnpcb77",]),
(["name":"�˵���",	"id":"ldk",	"mw":-1,	"tname":"bnpcb78",]),
(["name":"��������",	"id":"tjmb",	"mw":-1,	"tname":"bnpcb79",]),
(["name":"�Ѿ�ì��",	"id":"pjms",	"mw":-1,	"tname":"bnpcb80",]),
(["name":"���׵���",	"id":"tsdk",	"mw":-1,	"tname":"bnpcb81",]),
(["name":"�������� ",	"id":"jdgs",	"mw":-1,	"tname":"bnpcb82",]),
(["name":"�����ļҶ�",	"id":"bdjd",	"mw":-1,	"tname":"bnpcb83",]),
(["name":"�����ļ๤",	"id":"bdjg",	"mw":-1,	"tname":"bnpcb84",]),
(["name":"�����Ĵ���",	"id":"bdcf",	"mw":-1,	"tname":"bnpcb85",]),
(["name":"�ɻ��� ",	"id":"chz",	"mw":-1,	"tname":"bnpcb86",]),
(["name":"��ǹ����",	"id":"hqhw",	"mw":-1,	"tname":"bnpcb87",]),
(["name":"��թ�Ķ���",	"id":"qzds",	"mw":-1,	"tname":"bnpcb88",]),
(["name":"��ǹ��Ů ",	"id":"hqsn",	"mw":-1,"sex":1,	"tname":"bnpcb89",]),
(["name":"�ɹŽ���",	"id":"mgjl",	"mw":-1,	"tname":"bnpcb90",]),
(["name":"�������",	"id":"jgjl",	"mw":-1,	"tname":"bnpcb91",]),
(["name":"�ι�����",	"id":"sgjl",	"mw":-1,	"tname":"bnpcb92",]),
(["name":"��������ʿ",	"id":"yss",	"mw":-1,	"tname":"bnpcb93",]),
(["name":"�����ʿ",	"id":"swjs",	"mw":-1,	"tname":"bnpcb94",]),
(["name":"��������",	"id":"sw",	"mw":-1,	"tname":"bnpcb95",]),
(["name":"��Ӱ��ʿ",	"id":"wyys",	"mw":-1,	"tname":"bnpcb96",]),
(["name":"��͢����",	"id":"ctsw",	"mw":-1,	"tname":"bnpcb97",]),
(["name":"�ڷ�կ��Ӣ",	"id":"hfjy",	"mw":-1,	"tname":"bnpcb98",]),
(["name":"��Ĺ����",	"id":"dmmz",	"mw":-1,	"tname":"bnpcb99",]),
(["name":"��������",	"id":"hmls",	"mw":-1,	"tname":"bnpcb100",]),
(["name":"��Ů��˾",	"id":"mnjs",	"mw":-1,"sex":1,	"tname":"bnpcb101",]),
(["name":"��������",	"id":"blls",	"mw":-1,	"tname":"bnpcb102",]),
(["name":"�����ؾ�",	"id":"mlsj",	"mw":-1,	"tname":"bnpcb103",]),
(["name":"����������",	"id":"cgmsz",	"mw":-1,	"tname":"bnpcb104",]),
(["name":"������",	"id":"jydd",	"mw":-1,	"tname":"bnpcb105",]),
(["name":"ɽ������",	"id":"jxtf",	"mw":-1,	"tname":"bnpcb106",]),
(["name":"��������",	"id":"jhlz",	"mw":-1,	"tname":"bnpcb107",]),
(["name":"������ʹ��",	"id":"ttrsz",	"mw":-1,	"tname":"bnpcb108",]),
(["name":"�����˻���",	"id":"ttrhw",	"mw":-1,	"tname":"bnpcb109",]),
(["name":"���������",	"id":"tftqb",	"mw":-1,	"tname":"bnpcb110",]),
(["name":"���ľ�ʿ",	"id":"xxjs",	"mw":-1,	"tname":"bnpcb111",]),
(["name":"������",	"id":"xxmf",	"mw":-1,	"tname":"bnpcb112",]),
(["name":"����",	"id":"mb",	"mw":-1,	"tname":"bnpcb113",]),
(["name":"������",	"id":"jyw",	"mw":-1,	"tname":"bnpcb114",]),
(["name":"���ײ����",	"id":"tlbqb",	"mw":-1,	"tname":"bnpcb115",]),
(["name":"��Į����",	"id":"dmdk",	"mw":-1,	"tname":"bnpcb116",]),
(["name":"��˽���̶�",	"id":"zssd",	"mw":-1,	"tname":"bnpcb117",]),
(["name":"�����ٻ�",	"id":"dcbh",	"mw":-1,	"tname":"bnpcb118",]),
(["name":"����ǧ��",	"id":"dcqh",	"mw":-1,	"tname":"bnpcb119",]),
(["name":"��ˮ�����",	"id":"hsyqb",	"mw":-1,	"tname":"bnpcb120",]),
(["name":"�޾������",	"id":"jjbbz",	"mw":-1,	"tname":"bnpcb121",]),
(["name":"���կǿ��",	"id":"qfzqf",	"mw":-1,	"tname":"bnpcb122",]),
(["name":"���կǿ��",	"id":"qfzqf",	"mw":-1,	"tname":"bnpcb123",]),
(["name":"��������� ",	"id":"hgtqb",	"mw":-1,	"tname":"bnpcb124",]),
(["name":"������̽",	"id":"ddmt",	"mw":-1,	"tname":"bnpcb125",]),
(["name":"����ɮ ",	"id":"jws",	"mw":-1,	"tname":"bnpcb126",]),
(["name":"�ڷ�կ��� ",	"id":"hfzll",	"mw":-1,	"tname":"bnpcb127",]),
(["name":"ѲԺ�ӳ�",	"id":"xydz",	"mw":-1,	"tname":"bnpcb128",]),
(["name":"����",	"id":"qz",	"mw":-1,	"tname":"bnpcb129",]),
(["name":"�����ٱ�",	"id":"xxgb",	"mw":-1,	"tname":"bnpcb130",]),
(["name":"���ν���",	"id":"dsjj",	"mw":-1,	"tname":"bnpcb131",]),
(["name":"ƭ�˵���ף",	"id":"brmz",	"mw":-1,	"tname":"bnpcb132",]),
(["name":"���ǵ�ɱ��",	"id":"lpss",	"mw":-1,	"tname":"bnpcb133",]),
(["name":"���ŵĵ���",	"id":"lfdk",	"mw":-1,	"tname":"bnpcb134",]),
(["name":"���ŵ���Ů",	"id":"lfwn",	"mw":-1,"sex":1,	"tname":"bnpcb135",]),
(["name":"���ǵ���ʿ",	"id":"lpws",	"mw":-1,	"tname":"bnpcb136",]),
(["name":"�󹤹�ͷ",	"id":"kggt",	"mw":-1,	"tname":"bnpcb137",]),
(["name":"��ɽ����",	"id":"tsqz",	"mw":-1,	"tname":"bnpcb138",]),
(["name":"Сë��",	"id":"xmz",	"mw":-1,	"tname":"bnpcb139",]),
(["name":"������ʿ",	"id":"ddws",	"mw":-1,	"tname":"bnpcb140",]),
(["name":"Ū����",	"id":"nsr",	"mw":-1,	"tname":"bnpcb141",]),
(["name":"���˵���",	"id":"yrdk",	"mw":-1,	"tname":"bnpcb142",]),
(["name":"��ˮ����",	"id":"hsdk",	"mw":-1,	"tname":"bnpcb143",]),
(["name":"��ˮ��ʿ",	"id":"hsjs",	"mw":-1,	"tname":"bnpcb144",]),
(["name":"����������",	"id":"tzql",	"mw":-1,	"tname":"bnpcb145",]),
(["name":"����������",	"id":"dzyz",	"mw":-1,	"tname":"bnpcb146",]),
(["name":"�������",	"id":"jgjz",	"mw":-1,	"tname":"bnpcb147",]),
(["name":"Ѩ����Ұ��",	"id":"yr",	"mw":-1,	"tname":"bnpcb148",]),
(["name":"Ѩ��ŮҰ��",	"id":"nyr",	"mw":-1,"sex":1,	"tname":"bnpcb149",]),
(["name":"������ʿ",	"id":"qmws",	"mw":-1,	"tname":"bnpcb150",]),
(["name":"����ʿ",	"id":"wss",	"mw":-1,	"tname":"bnpcb151",]),
(["name":"������",	"id":"hyr",	"mw":-1,	"tname":"bnpcb152",]),
(["name":"С͵",	"id":"xt",	"mw":-1,	"tname":"bnpcb153",]),
(["name":"��ðɮ��",	"id":"jmsr",	"mw":-1,	"tname":"bnpcb154",]),
(["name":"Ǳ��ɮ��",	"id":"qtsl",	"mw":-1,	"tname":"bnpcb155",]),
(["name":"ɽ�ϱ���",	"id":"snbm",	"mw":-1,	"tname":"bnpcb156",]),
(["name":"���½�ʿ",	"id":"wyjs",	"mw":-1,	"tname":"bnpcb157",]),
(["name":"������ͷĿ",	"id":"xxztm",	"mw":-1,	"tname":"bnpcb158",]),
(["name":"������ʿ",	"id":"nyys",	"mw":-1,	"tname":"bnpcb159",]),
(["name":"���ļ�˾",	"id":"nyjs",	"mw":-1,	"tname":"bnpcb160",]),
(["name":"������Ů",	"id":"tzwn",	"mw":-1,"sex":1,	"tname":"bnpcb161",]),
(["name":"�����ļ���",	"id":"bdjm",	"mw":-1,	"tname":"bnpcb162",]),
(["name":"��������",	"id":"yyxk",	"mw":-1,	"tname":"bnpcb163",]),
(["name":"ɱ�˵��Ի�",	"id":"srlh",	"mw":-1,	"tname":"bnpcb164",]),
(["name":"������",	"id":"xxz",	"mw":-1,	"tname":"bnpcb165",]),
(["name":"����ʿ",	"id":"jrjs",	"mw":-1,	"tname":"bnpcb166",]),
(["name":"ɽ������",	"id":"sbdf",	"mw":-1,	"tname":"bnpcb167",]),
(["name":"����ʿ",	"id":"yjs",	"mw":-1,	"tname":"bnpcb168",]),
(["name":"���ȭʦ",	"id":"trqs",	"mw":-1,	"tname":"bnpcb169",]),
(["name":"����ʿ",	"id":"yjs",	"mw":-1,	"tname":"bnpcb170",]),
(["name":"�ξ�����",	"id":"yjdb",	"mw":-1,	"tname":"bnpcb171",]),
(["name":"�ƼҶ�ʹ",	"id":"tjds",	"mw":-1,	"tname":"bnpcb172",]),
(["name":"�Ƽ����� ",	"id":"tjns",	"mw":-1,	"tname":"bnpcb173",]),
(["name":"�������׼�����",	"id":"plmr",	"mw":-1,	"tname":"bnpcb174",]),
(["name":"����ǹ��",	"id":"hlqb",	"mw":-1,	"tname":"bnpcb175",]),
(["name":"��������",	"id":"hlns",	"mw":-1,	"tname":"bnpcb176",]),
(["name":"���Ӫꢱ�",	"id":"rjyzb",	"mw":-1,	"tname":"bnpcb177",]),
(["name":"���Ӫ���� ",	"id":"rjyjr",	"mw":-1,	"tname":"bnpcb178",]),
(["name":"�н�����",	"id":"xjsr",	"mw":-1,	"tname":"bnpcb179",]),
(["name":"��������",	"id":"nmdk",	"mw":-1,	"tname":"bnpcb180",]),
(["name":"������Ů",	"id":"nmwn",	"mw":-1,"sex":1,	"tname":"bnpcb181",]),
(["name":"��������",	"id":"smsr",	"mw":-1,	"tname":"bnpcb182",]),
(["name":"���ڸ���",	"id":"dngs",	"mw":-1,	"tname":"bnpcb183",]),
(["name":"�����ܹ�",	"id":"dnzg",	"mw":-1,	"tname":"bnpcb184",]),
(["name":"ˮ�����",	"id":"sfyf",	"mw":-1,	"tname":"bnpcb185",]),
(["name":"��Ҿ������� ",	"id":"wjfs",	"mw":-1,	"tname":"bnpcb186",]),
(["name":"��Ҿ���ǹ�� ",	"id":"wjqs",	"mw":-1,	"tname":"bnpcb187",]),
(["name":"Ǯ�Ϸ˱�",	"id":"qsfb",	"mw":-1,	"tname":"bnpcb188",]),
(["name":"�ɹŴ��",	"id":"mgdf",	"mw":-1,	"tname":"bnpcb189",]),
(["name":"����ʿ",	"id":"dls",	"mw":-1,	"tname":"bnpcb190",]),
(["name":"��������",	"id":"mysx",	"mw":-1,	"tname":"bnpcb191",]),
(["name":"ǿ��ͷĿ",	"id":"qxtm",	"mw":-1,	"tname":"bnpcb192",]),
(["name":"����",	"id":"mz",	"mw":-1,	"tname":"bnpcb193",]),
(["name":"���ҵ�����",	"id":"plya",	"mw":-1,	"tname":"bnpcb194",]),
(["name":"����ɮ��",	"id":"yysr",	"mw":-1,	"tname":"bnpcb195",]),
(["name":"�̲���ͷ",	"id":"xbbt",	"mw":-1,	"tname":"bnpcb196",]),
(["name":"���µĲ˷�",	"id":"nscf",	"mw":-1,	"tname":"bnpcb197",]),
(["name":"�ٸ�����",	"id":"gfbk",	"mw":-1,	"tname":"bnpcb198",]),
(["name":"�׻��û���",	"id":"bhthw",	"mw":-1,	"tname":"bnpcb199",]),
(["name":"�������",	"id":"cbbz",	"mw":-1,	"tname":"bnpcb200",]),
});




 


void create()
{
	mapping npc;
	string weapon,tname;
	npc=data[124+random(2)];
	//weapon=npc["weapon"];

	set_name(order[random(13)] +npc["name"]+NOR,({ npc["id"] }));
	tname=npc["tname"];
	set("tname",tname);
	set("age",20+random(30));
	set("gender", "����");
	if (npc["sex"]) set("gender", "Ů��");
set("str",25+random(5));
set("dex",25+random(5));
set("con",25+random(5));
set("int",25+random(5));
set("per",25+random(5));
set("kar",25+random(5));
	set("combat_exp",371694959);

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
	set("mgnpc",1);
	set_skill("dodge",30);
	//set("shen_type",npc["mw"]);

	setup();
	//carry_object("/clone/misc/cloth")->wear();
	initlvl(658,62+random(2));
	this_object()->delete("nickname");
	//if( weapon)
	//	carry_object("/clone/weapon/"+weapon)->wield();
	add_money("silver",18+random(20));
}
       
void unconcious()
{
    die();
}

void die()
{
	string msg;
int i,pot,exp,shen;
	object killer;
	exp= random(188)+188+(187*2);
	pot= exp*2/3+1;
	if( objectp(killer = query_temp("last_damage_from")))
{
	if (userp(killer))
{
	killer->add_temp(this_object()->query("tname"),1);
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
		ob->set_name(order[random(13)] +npc["name"]+NOR,({ npc["id"] }));
}

void init()
{
        remove_call_out("leave");
        call_out("leave",66);
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