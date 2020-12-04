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
	      set_name("[1;31mÉ½È±[2;37;0m", ({ "fengyun cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;35mËùÎ½·çÔÆ¼Ê»á£¬ÌìµØ±äÉ«£¡ÕÌ´ËĞĞÇ§Àï£¬ÀÏÄ§Ğ¡³ó£¬Æñ¿°Ò»»÷£¡
[2;37;0mÕâÊÇÒ»¼şÓÉ¾ø¶Ô¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØ°Ë½ïËÄÁ½ÁùÇ®µÄ[1;35m·çÔÆÖ®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´¾ø¶Ô¼á¹Ì£¬¾ßÓĞ[31mÎŞÓëÂ×±È[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[40mµØ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [31m»ğ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [33mÍÁ[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;32mÄ§Íõ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÌìÓî:[34mÏ¸Ëé[2;37;0m ÌìÔ¨:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[35m±ê×¼[2;37;0m 
°×Ê¯:[31m¾«ÖÂ[2;37;0m ÉÁµç:[35m±ê×¼[2;37;0m 
³¤Éú:[33mºÜ¸ß[2;37;0m ÍşÁ¦:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m»¨ÎŞÀâ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÈ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "enjoy");
		set("ownername", "»¨ÎŞÀâ");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",48);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",33);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 66);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 53);


    set("armor_prop/armor", 609);
    set("armor_prop/defense", 56);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 49);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 56);
    set("armor_prop/damage", 159);

    set("wtypeA",6);
    set("wtypeB",6);
    set("wtypeC",6);
    set("wtypeD",10);
    set("wtypeE",11);
    set("wtypeF",9);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",14);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "staff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";