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
	set_name("[1;32mÎŞ¼«Ö®½£[2;37;0m", ({ "wuji sword", "sword" }));
	set_weight(5300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;32m´ËÎïÒÑ´ï³öÉñÈë»¯£¬µÇ·åÔì¼«£¬ÉñºõÆäÉñÖ®¾³½ç£¡Ë×ËµÍòÎï¹é×Ú£¬±ãÊÇÕâ¡°ÎŞ¼«¡±£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉ¾ø¶Ô¼áÓ²µÄ[37mĞşÌú[2;37;0mÖÆ³É£¬ÖØÊ®½ïÁùÁ½ÁãÇ®µÄ[1;32mÎŞ¼«Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´¾ø¶Ô·æÀû£¬¾ßÓĞ[1;31mÌìÏÂÎŞË«[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;31mÎŞË«[2;37;0m [36mÄ¾[2;37;0m:[31m¾«ÖÂ[2;37;0m [32mË®[2;37;0m:[1;33mÌìÊ¥[2;37;0m [31m»ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [33mÍÁ[2;37;0m:[35m±ê×¼[2;37;0m [1;37mÀ×[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ¾ø´ú:[34mÏ¸Ëé[2;37;0m ÌìĞş:[34mÏ¸Ëé[2;37;0m °×Ê¯:[32m´Ö²Ú[2;37;0m ÉÁµç:[32m´Ö²Ú[2;37;0m 
ÖÜÌì:[34mÏ¸Ëé[2;37;0m ³¤Éú:[35m±ê×¼[2;37;0m ²»ÀÏ:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÌìÕı[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m¸«·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "ÌìÕı");
		set("value", 25000);
		set("weapon_prop/intelligence",40);
		set("weapon_prop/strength",40);
		set("weapon_prop/karey",56);
		set("weapon_prop/percao",29);
		set("weapon_prop/dexerity",40);
		set("weapon_prop/constitution",26);
    set("weapon_prop/dodge", 37);
    set("weapon_prop/parry", 40);
    set("weapon_prop/attack", 48);
    set("weapon_prop/armor", 40);
    set("weapon_prop/defense", 48);
    
    set("weapon_prop/neili", 27);
    set("weapon_prop/qi", 55);
    set("weapon_prop/jing", 30);
    set("weapon_prop/jingli", 30);
    set("weapon_prop/damage", 0);

    set("wtypeA",12);
    set("wtypeB",6);
    set("wtypeC",10);
    set("wtypeD",8);
    set("wtypeE",5);
    set("wtypeF",6);
    set("wtypeG",8);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",4);
    set("wtypeL",4);
    

                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 16);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(1615);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";