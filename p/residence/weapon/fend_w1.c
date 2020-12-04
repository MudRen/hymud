// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[1;36m����֮��[2;37;0m", ({ "kunlun sword", "sword" }));
	set_weight(4410);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[1;36m	Ц�����˼�ʮ���Σ��ո�����ͷ��
	��ͭ���ﲴ���������죬�������ƣ� 
	����ʫ���ζϣ��Ϲ����� 
	�ѽ���Ȼ�����޴��й��ۡ� 
 
	��������·Զ����˭�����壬ŪӰ���ޣ�
	��Ӣ�۶�Ů�������Ž�
	�����ܵƻ����ʣ���꼻�һ�ֺ����ݣ�
	Ʈ��ߣ��������ƴ����� 
[2;37;0m����һ�����ޱȼ�Ӳ��[31m��������[2;37;0m�Ƴɣ��ذ˽������Ǯ��[1;36m����֮��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȷ���������[1;36mն����ħ[2;37;0m��������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;31m����[2;37;0m [1;33m��[2;37;0m:[1;36m����[2;37;0m [32mˮ[2;37;0m:[1;33m��ʥ[2;37;0m [33m��[2;37;0m:[1;31m����[2;37;0m [1;35m��[2;37;0m:[1;32mħ��[2;37;0m 

���滹����һЩ���֣�
����:[1;31m����[2;37;0m ����:[34mϸ��[2;37;0m ��Ԩ:[34mϸ��[2;37;0m ����:[1;36m����[2;37;0m 
��ʯ:[31m����[2;37;0m ����:[1;36m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����[2;37;0m ������һЩ�� [1;32m�ڹ�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "fend");
		set("ownername", "����");
		set("value", 25000);
		set("weapon_prop/intelligence",56);
		set("weapon_prop/strength",40);
		set("weapon_prop/karey",56);
		set("weapon_prop/percao",40);
		set("weapon_prop/dexerity",40);
		set("weapon_prop/constitution",56);
    set("weapon_prop/dodge", 66);
    set("weapon_prop/parry", 48);
    set("weapon_prop/attack", 56);
    set("weapon_prop/armor", 74);
    set("weapon_prop/defense", 56);
    
    set("weapon_prop/neili", 56);
    set("weapon_prop/qi", 74);
    set("weapon_prop/jing", 56);
    set("weapon_prop/jingli", 56);
    set("weapon_prop/damage", 0);

    set("wtypeA",7);
    set("wtypeB",7);
    set("wtypeC",10);
    set("wtypeD",6);
    set("wtypeE",14);
    set("wtypeF",9);
    set("wtypeG",6);
    set("wtypeH",6);
    set("wtypeI",14);
    set("wtypeJ",7);
    set("wtypeK",7);
    set("wtypeL",7);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(1191);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";