#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[31mÄªĞ°Ö®·ş×°[2;37;0m", ({ "moye cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[31mÄªĞ°·æÀûÎŞ±È£¬ÄÜ¿ªÌì±ÙµØ£¬µ´Ñı³ıÄ§£¡
[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0m¼ÓÉÏ[1;33mÁú¼ë²ÏË¿[2;37;0mÖÆ³É£¬ÖØËÄ½ïÁãÁ½¾ÅÇ®µÄ[31mÄªĞ°Ö®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[1;33m¾ÙÊÀÎŞÆ¥[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;31m»ÙÌì[2;37;0m [36mÄ¾[2;37;0m:[1;31mÎŞË«[2;37;0m [1;35m·ç[2;37;0m:[1;31m´´ÊÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;34mµç[2;37;0m:[1;31m´´ÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÌìÓî:[33mºÜ¸ß[2;37;0m ÇÉÖÆ:[1;34m¾ÙÊÀ[2;37;0m 
×ÏÊ¯:[33mºÜ¸ß[2;37;0m ÉÁµç:[1;32mÄ§Íõ[2;37;0m 
ÖÜÌì:[31m¾«ÖÂ[2;37;0m ³¤Éú:[1;34m¾ÙÊÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÊ·µÙ·ÒÖÜ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m½£·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

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
		set("ownername", "Ê·µÙ·ÒÖÜ");
		set("value", 36000);
		set("armor_prop/intelligence",8);
		set("armor_prop/strength",43);
		set("armor_prop/karey",8);
		set("armor_prop/percao",8);
		set("armor_prop/dexerity",8);
		set("armor_prop/constitution",16);
    set("armor_prop/dodge", 16);
    set("armor_prop/parry", 41);
    set("armor_prop/attack", 94);


    set("armor_prop/armor", 889);
    set("armor_prop/defense", 24);
    
    set("armor_prop/neili", 65);
    set("armor_prop/qi", 87);
    set("armor_prop/jing", 32);
    set("armor_prop/jingli", 24);
    set("armor_prop/damage", 52);

    set("wtypeA",15);
    set("wtypeB",12);
    set("wtypeC",0);
    set("wtypeD",6);
    set("wtypeE",0);
    set("wtypeF",14);
    set("wtypeG",8);
    set("wtypeH",14);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 20);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";