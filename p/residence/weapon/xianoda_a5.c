#include <ansi.h> 
#include <armor.h>

inherit HEAD;

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

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[34m����֮ͷ��[2;37;0m", ({ "qixing head", "head" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[34m����֮ͷ��[2;37;0m����һ�����ޱȼ�Ӳ��[1;33m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ�������������Ǯ��[34m����֮ͷ��[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������ޱȼ�̣�����[36m��С[2;37;0m�ķ�������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[1;31m��˫[2;37;0m [33m��[2;37;0m:[1;34m����[2;37;0m [1;35m��[2;37;0m:[1;36m����[2;37;0m 
[1;37m��[2;37;0m:[1;31m��˫[2;37;0m [1;34m��[2;37;0m:[1;35m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m��˫[2;37;0m ��Դ:[34mϸ��[2;37;0m 
����:[34mϸ��[2;37;0m 
��ʯ:[34mϸ��[2;37;0m ����:[32m�ֲ�[2;37;0m 
����:[32m�ֲ�[2;37;0m ����:[33m�ܸ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mʷ�ٷ���[2;37;0m ������һЩ�� [1;32m�޷�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xianoda");
		set("ownername", "ʷ�ٷ���");
		set("value", 16000);
		set("armor_prop/intelligence",32);
		set("armor_prop/strength",40);
		set("armor_prop/karey",21);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",16);
		set("armor_prop/constitution",8);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 26);
    set("armor_prop/attack", 32);


    set("armor_prop/armor", 250);
    set("armor_prop/defense", 16);
    
    set("armor_prop/neili", 24);
    set("armor_prop/qi", 36);
    set("armor_prop/jing", 46);
    set("armor_prop/jingli", 46);
    set("armor_prop/damage", 106);

    set("wtypeA",0);
    set("wtypeB",12);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",8);
    set("wtypeF",7);
    set("wtypeG",12);
    set("wtypeH",11);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";